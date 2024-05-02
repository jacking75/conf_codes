
#include <array>
#include <iostream>

int main()
{
	std::array<int, 5> arr1 = { 11, 12, 13, 14, 15 };

	std::cout << arr1.at(2) << std::endl;
	std::cout << arr1.front() << std::endl;
	std::cout << arr1.back() << std::endl;

	int* pData = arr1.data();
	std::cout << pData[3] << std::endl;

	return 0;
}


