// 출처: http://daisukekobayashi.com/blog/boost-log-logging-console-windows-and-file

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/empty_deleter.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>

void InitLogging()
{
	namespace logging = boost::log;
	namespace expr = boost::log::expressions;
	namespace sinks = boost::log::sinks;
	namespace keywords = boost::log::keywords;

	logging::add_common_attributes();

	boost::shared_ptr<logging::core> core = logging::core::get();

	// 콘솔
	// 1. 백엔드
	boost::shared_ptr<sinks::text_ostream_backend> ostream_backend =
								boost::make_shared<sinks::text_ostream_backend>();
	ostream_backend->add_stream(
					boost::shared_ptr<std::ostream>(&std::clog, logging::empty_deleter()));
	ostream_backend->auto_flush(true);

	// sink
	typedef sinks::synchronous_sink<sinks::text_ostream_backend> sink_ostream_t;
	boost::shared_ptr<sink_ostream_t> sink_ostream(new sink_ostream_t(ostream_backend));
	sink_ostream->set_formatter(
		expr::format("[%1%] [%2%]\t%3%")
		% expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
		% logging::trivial::severity
		% expr::message);

	// 코에에 sink 붙이기
	core->add_sink(sink_ostream);


	// 파일
	// 1. 백엔드
	boost::shared_ptr<sinks::text_file_backend> text_backend =
		boost::make_shared<sinks::text_file_backend>(
		keywords::file_name = "log/%Y-%m-%d_%H-%M.log",
		keywords::rotation_size = 10 * 1024 * 1024,
		keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0));

	text_backend->auto_flush(true);

	// sink
	typedef sinks::synchronous_sink<sinks::text_file_backend> sink_text_t;
	boost::shared_ptr<sink_text_t> sink_text(new sink_text_t(text_backend));

	sink_text->set_formatter(
		expr::format("[%1%] [%2%]\t%3%")
		% expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
		% logging::trivial::severity
		% expr::message);

	// 코에에 sink 붙이기
	core->add_sink(sink_text);
}

int main() 
{

	InitLogging();

	BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
	BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
	BOOST_LOG_TRIVIAL(info) << "An informational severity message";
	BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
	BOOST_LOG_TRIVIAL(error) << "An error severity message";
	BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

	return 0;
}

