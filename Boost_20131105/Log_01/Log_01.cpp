// 출처: http://kkayataka.hatenablog.com/entry/2013/07/31/073030

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>

#ifdef __APPLE__
  #define BOOST_LOG_DYN_LINK
#endif

#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sinks/debug_output_backend.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/empty_deleter.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/trivial.hpp>

int main() 
{
  using namespace boost;
  namespace logging = boost::log;
  namespace expr = boost::log::expressions;
  namespace sinks = boost::log::sinks;
  namespace keywords = boost::log::keywords;

#ifdef _WIN32
  { // for Visual Studio
    shared_ptr<sinks::debug_output_backend> backend = make_shared<sinks::debug_output_backend>();
    
    typedef sinks::synchronous_sink<sinks::debug_output_backend> sink_t;
    shared_ptr<sink_t> sink(new sink_t(backend));

    sink->set_formatter(
    expr::format("%1%\t%2%\t%3%\n")
      % expr::format_date_time<posix_time::ptime>(
        "TimeStamp", "%H:%M:%S")
      % logging::trivial::severity
      % expr::message
    );
	
    logging::core::get()->add_sink(sink);
  }
#endif

  { 
	// for std::clog 콘솔 출력
    shared_ptr<sinks::text_ostream_backend> backend = make_shared<sinks::text_ostream_backend>();
    backend->add_stream( shared_ptr<std::ostream>(&std::clog, logging::empty_deleter()) );
    backend->auto_flush(true);

    typedef sinks::synchronous_sink<sinks::text_ostream_backend> sink_t;
    shared_ptr<sink_t> sink(new sink_t(backend));

    sink->set_formatter(
      expr::format("%1% [%2%] %3%")
      % expr::format_date_time<posix_time::ptime>(
	    "TimeStamp", "%Y-%m-%d %H:%M:%S")
      % logging::trivial::severity
      % expr::message
      );

    logging::core::get()->add_sink(sink);
  }

  { 
	// for file
    logging::add_file_log(
    keywords::auto_flush = true,
    keywords::open_mode = std::ios::app,
    keywords::target = "log",
    keywords::file_name = "log/app_%Y%m%d.log",
    keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
    keywords::max_size = 10 * 1024 * 1024,
    keywords::format = expr::format("%1%\t%2%\t%3%")
      % expr::format_date_time<posix_time::ptime>(
        "TimeStamp", "%Y-%m-%d %H:%M:%S")
      % logging::trivial::severity
      % expr::message
      );
  }

  logging::add_common_attributes();

#ifdef _DEBUG
  // do nothing
#else
  logging::core::get()->set_filter(
    logging::trivial::severity >= logging::trivial::info
    );
#endif

  BOOST_LOG_TRIVIAL(trace) << "trace message";
  BOOST_LOG_TRIVIAL(debug) << "debug";
  BOOST_LOG_TRIVIAL(info) << "info message";
  BOOST_LOG_TRIVIAL(warning) << "warning message";
  BOOST_LOG_TRIVIAL(error) << "error message";
  BOOST_LOG_TRIVIAL(fatal) << "fatal message";

  logging::core::get()->remove_all_sinks();
}