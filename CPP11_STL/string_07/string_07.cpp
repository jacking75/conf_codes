
#include <iostream>
#include <string>


int main()
{
	std::string packetData("[type]6[data]hello[data]none");
	
	std::string::size_type pos = packetData.find("[data]");
	std::cout << "[data] 위치: " << pos << std::endl;

	pos = packetData.rfind("[data]");
	std::cout << "[data] 위치: " << pos << std::endl;

	pos = packetData.find_first_of("[data]");
	std::cout << "[data] 위치: " << pos << std::endl;

	// 마지막 [data]의 ]의 위치를 반환한다.
	pos = packetData.find_last_of("[data]");
	std::cout << "[data] 위치: " << pos << std::endl;

	pos = packetData.find_first_not_of("[");
	std::cout << "[ 이 아닌 첫 위치: " << pos << std::endl;

	pos = packetData.find_last_not_of("]");
	std::cout << "] 이 이 아닌 마지막 위치: " << pos << std::endl;

	return 0;
}


