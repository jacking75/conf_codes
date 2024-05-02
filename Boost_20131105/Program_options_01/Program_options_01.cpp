// ��ó: http://neive.tistory.com/316
 // --help --ip 192.168.0.1

#include <boost\program_options.hpp>
 
namespace po = boost::program_options;
 
int main(int argc, char* argv[])
{
    // �ƱԸ�Ʈ �ɼǿ� ���� ����
    po::options_description desc("��밡���� �ɼǵ�");
    desc.add_options()
        ("help", "������ ���ϴ�")
        ("ip", po::value<std::string>(), "������ ������ ip �� �Է��մϴ�")
    ;
 
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);   
 
    // --help �� ���� �� ����
    if (vm.count("help")) {
        std::cout << desc << "\n";  // ������ ���
	}

    // --ip �� ���� �� ����
    if (vm.count("ip"))
    {
        std::string ip = vm["ip"].as<std::string>();
        std::cout << "���� ip �� �����մϴ�. " << ip << std::endl;
    }
    else
	{
        std::cout << "������ ip �� �Էµ��� �ʾҽ��ϴ� default ip �� �����մϴ�." << std::endl;
	}

    int n;
    std::cout << "wait... " << std::endl;
    std::cin >> n;
 
    return 0;
}