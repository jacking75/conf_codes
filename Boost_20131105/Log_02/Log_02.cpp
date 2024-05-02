// 출처: http://d.hatena.ne.jp/faith_and_brave/20130725/1374736211
// 「타임스탬프」「스레드 ID」「중요도(구분, severity level)」「메시지」

#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>

int main()
{
    // 필터 없이 로깅
    // 각 구분만다 로그 출력各
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";


    // 로그에 필터를 붙인다
	std::cout << "필터링 사용" << std::endl;

    // info 이상만 출력하도록
    using namespace boost::log;
    core::get()->set_filter
    (
        trivial::severity >= trivial::info
    );

    // 필터가 붙은 로깅
    // trace와 debug는 출력되지 않는다
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
}
