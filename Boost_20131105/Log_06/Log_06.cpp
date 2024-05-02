// 출처: http://d.hatena.ne.jp/faith_and_brave/20130802/1375427047

#include <boost/log/trivial.hpp>
// 시간 or 파일 크기로 로테이션
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/attributes.hpp>

#include <boost/thread.hpp>
#include <boost/chrono/duration.hpp>

namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;
namespace sinks = boost::log::sinks;

int main()
{
    // 로그 파일 출력 설정
    // logs 디렉토리에 「년_월_일.log」라는 파일명으로 로그 출력
    // 0시 0분 0초에 새로운 로그 파일을 만든다
    boost::log::add_file_log(
        keywords::file_name = "logs/%Y_%m_%d.log",
        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
        keywords::format = "[%TimeStamp%]: %Message%"
    );

    // 타임 스탬프 속성을 설정(로컬 시간)
    boost::log::core::get()->add_global_attribute("TimeStamp", attrs::local_clock());

    for (int i = 0; i < 1000; ++i) 
	{
        BOOST_LOG_TRIVIAL(info) << "hello";
        boost::log::core::get()->flush();

        // 30초 마다 출력
        boost::this_thread::sleep_for(boost::chrono::seconds(30));
    }
}