// 출처: http://faithandbrave.hateblo.jp/entry/20130802/1375427047
// 자동 flush

#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/attributes.hpp>

#include <boost/thread.hpp>
#include <boost/chrono/duration.hpp>


int main()
{
	boost::log::add_file_log(
		boost::log::keywords::file_name = "logs/%Y_%m_%d.log",
		boost::log::keywords::time_based_rotation =
		boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
		boost::log::keywords::format = "[%TimeStamp%]: %Message%",

		boost::log::keywords::auto_flush = true
		);

	boost::log::core::get()->add_global_attribute("TimeStamp",
		boost::log::attributes::local_clock());

	for (int i = 0; i < 1000; ++i)
	{
		BOOST_LOG_TRIVIAL(info) << "hello";
		//boost::log::core::get()->flush();
		boost::this_thread::sleep_for(boost::chrono::seconds(30));
	}
}
