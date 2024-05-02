
#include <iostream>
#include <string>


int main()
{
	std::string packetData("[type]6[data]hello");
	std::cout << "packetData: " << packetData << std::endl;

	std::string::size_type pos1 = packetData.find("]");
	std::cout << "] 위치: " << pos1 << std::endl;

	std::string::size_type pos2 = packetData.rfind("[data]");
	std::cout << "[data] 위치: " << pos2 << std::endl;

	std::string typeValue = packetData.substr(pos1+1, (pos2-pos1)-1);
	std::cout << "type의 값: " << typeValue << std::endl;

	return 0;
}


