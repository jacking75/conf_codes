// 출처: http://kkayataka.hatenablog.com/entry/2013/07/27/110244

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>

#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sinks/debug_output_backend.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/trivial.hpp>

int main() 
{
	boost::shared_ptr<boost::log::sinks::debug_output_backend> backend =
		boost::make_shared<boost::log::sinks::debug_output_backend>();

	typedef boost::log::sinks::synchronous_sink<boost::log::sinks::debug_output_backend> sink_t;
	boost::shared_ptr<sink_t> sink(new sink_t(backend));

	sink->set_formatter(
		boost::log::expressions::format("%1%\t%2%\t%3%\n")
		% boost::log::expressions::format_date_time<boost::posix_time::ptime>(
		"TimeStamp", "%H:%M:%S")
		% boost::log::trivial::severity
		% boost::log::expressions::message
		);

	boost::log::core::get()->add_sink(sink);

	boost::log::add_common_attributes();

#ifdef _DEBUG
	// do nothing
#else
	boost::log::core::get()->set_filter(
		boost::log::trivial::severity >= boost::log::trivial::info
		);
#endif

	BOOST_LOG_TRIVIAL(trace) << "trace message";
	BOOST_LOG_TRIVIAL(debug) << "debug";
	BOOST_LOG_TRIVIAL(info) << "info message";
	BOOST_LOG_TRIVIAL(warning) << "warning message";
	BOOST_LOG_TRIVIAL(error) << "error message";
	BOOST_LOG_TRIVIAL(fatal) << "fatal message";

	return 0;
}
