

#include <boost/thread/thread.hpp>
#include <iostream>


int main()
{
	std::cout << "�ϵ���� ���ؽ�Ʈ �� : " << boost::thread::hardware_concurrency() << std::endl;
	return 0;
}
