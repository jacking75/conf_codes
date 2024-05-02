
#include <iostream>
#include <string>


int main()
{
	std::string ID1 = "jacking";
	auto hash1 = std::hash<std::string>()(ID1);
	std::cout << "jacking의 해시 값: " << hash1 << std::endl;

	std::string ID2 = "jacking75";
	auto hash2 = std::hash<std::string>()(ID2);
	std::cout << "jacking75의 해시 값: " << hash2 << std::endl;

	return 0;
}

