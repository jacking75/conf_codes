
#include <thread>
#include <iostream>


int main()
{
	std::cout << "하드웨어 컨텍스트 수 : " << std::thread::hardware_concurrency() << std::endl;
	return 0;
}

