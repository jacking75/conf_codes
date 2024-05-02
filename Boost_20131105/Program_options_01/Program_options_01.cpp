// 출처: http://neive.tistory.com/316
 // --help --ip 192.168.0.1

#include <boost\program_options.hpp>
 
namespace po = boost::program_options;
 
int main(int argc, char* argv[])
{
    // 아규먼트 옵션에 대한 설명
    po::options_description desc("사용가능한 옵션들");
    desc.add_options()
        ("help", "도움말을 봅니다")
        ("ip", po::value<std::string>(), "접속할 서버의 ip 를 입력합니다")
    ;
 
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);   
 
    // --help 가 있을 때 실행
    if (vm.count("help")) {
        std::cout << desc << "\n";  // 설명을 출력
	}

    // --ip 가 있을 때 실행
    if (vm.count("ip"))
    {
        std::string ip = vm["ip"].as<std::string>();
        std::cout << "다음 ip 로 접속합니다. " << ip << std::endl;
    }
    else
	{
        std::cout << "접속할 ip 가 입력되지 않았습니다 default ip 로 접속합니다." << std::endl;
	}

    int n;
    std::cout << "wait... " << std::endl;
    std::cin >> n;
 
    return 0;
}