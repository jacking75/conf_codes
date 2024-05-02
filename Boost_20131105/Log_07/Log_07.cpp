// 커스텀 로그 레벨 사용하기 
// 출처: http://suikaba.hatenablog.com/entry/2013/08/02/191734

#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/support/date_time.hpp>

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;

enum severity_level
{
    debug,
    warning,
    error,
    critical
};
struct severity_tag;

std::ostream& operator<< ( std::ostream& strm, severity_level level )
{
    static const char* strs[] =
    {
        "debug",
        "warning",
        "error",
        "critical"
    };

    if ( static_cast< std::size_t >( level ) < sizeof( strs ) / sizeof( *strs ) )
        strm << strs[level];
    else
        strm << static_cast< int >( level );

    return strm;
}

int main()
{
    logging::register_simple_formatter_factory< severity_level, char >( "Severity" );
    
	logging::add_file_log(
        keywords::file_name = "logs/%Y%m%d.log",
        keywords::time_based_rotation = sinks::file::rotation_at_time_point( 0, 0, 0 ),
        keywords::format = 
        (
            expr::stream
                << expr::attr< unsigned int >( "LineID" ) << ":"
                << "[" << expr::format_date_time< boost::posix_time::ptime >( "TimeStamp", "%Y-%m-%d %H:%M:%S" )
                << "][" << expr::attr< severity_level, severity_tag >( "Severity" )
                << "]: " << expr::smessage
        ),
        
        // keywords::format = "%LineID%:[%TimeStamp%][%Severity%]:%Message%"
        keywords::open_mode = (std::ios::out | std::ios::app) // std::ios 그대로 사용
    );

    logging::sources::severity_logger<severity_level> slg;
    logging::add_common_attributes(); // LineID를 사용할 수 있도록 한다
    logging::core::get()->add_global_attribute( "TimeStamp", attrs::local_clock() );
    
	BOOST_LOG_SEV( slg, debug ) << "hoge";
    BOOST_LOG_SEV( slg, error ) << "bar";
    BOOST_LOG_SEV( slg, warning ) << "piyo";
    BOOST_LOG_SEV( slg, critical ) << "foo";
}
