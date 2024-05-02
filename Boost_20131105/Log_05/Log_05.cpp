// 출처: http://d.hatena.ne.jp/faith_and_brave/20130801/1375340888
// 파일 크기로 로테이션

#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/attributes.hpp>

namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

int main()
{
    // 로그 파일 출력 설정
    // logs 디렉토리에 「년월일_시분초_번호.log」라는 파일명으로 로그 출력
    // 1 파일당 1KB로 나눈다
    boost::log::add_file_log(
        keywords::file_name = "logs/%Y%m%d_%H%M%S_%5N.log",
        keywords::rotation_size = 10 * 1024,
        keywords::format = "[%TimeStamp%]: %Message%"
    );

    // 타임 스탬프 속성을 설정(로컬 시간)
    boost::log::core::get()->add_global_attribute("TimeStamp", attrs::local_clock());

    for (int i = 0; i < 1000; ++i) 
	{
        BOOST_LOG_TRIVIAL(info) << "hello";
    }
}
