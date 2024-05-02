// 출처: http://faithandbrave.hateblo.jp/entry/20130801/1375340888

#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/attributes.hpp>

int main()
{
	boost::log::add_file_log(
		boost::log::keywords::file_name = "logs/%Y%m%d_%H%M%S_%5N.log",
		boost::log::keywords::rotation_size = 10 * 1024,
		boost::log::keywords::format = "[%TimeStamp%]: %Message%"
		);

	// 타임 스탬프의 속성 설정(로컬 시간으로)
	boost::log::core::get()->add_global_attribute("TimeStamp", 
							boost::log::attributes::local_clock());

	for (int i = 0; i < 1000; ++i) 
	{
		BOOST_LOG_TRIVIAL(info) << "hello,hello,hello,hello,hello,hello,";
	}

	return 0;
}



