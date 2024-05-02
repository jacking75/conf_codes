
#include <iostream>
#include <string>


int main()
{
	std::string value1 = "11";
	int nValue1 = std::stoi(value1);
	std::cout << "value1: " << nValue1 << std::endl;

	int nValue2 = 15;
	std::string value2 = std::to_string(nValue2);
	std::cout << "nValue2: " << value2 << std::endl;

	return 0;
}

