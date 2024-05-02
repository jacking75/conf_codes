// 출처: http://d.hatena.ne.jp/faith_and_brave/20130726/1374820081
// 파일에 출력

#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>

int main()
{
	boost::log::add_file_log("log.txt");
	
	BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
	BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
	BOOST_LOG_TRIVIAL(info) << "An informational severity message";
	BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
	BOOST_LOG_TRIVIAL(error) << "An error severity message";
	BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

	return 0;
}