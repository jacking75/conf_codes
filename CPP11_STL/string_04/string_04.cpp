
#include <iostream>
#include <string>


int main()
{
	std::string s1("HeroCompany");
	std::cout << "s1: " << s1 << std::endl;


	std::cout << "s1의 세번째 위치의 문자: " << s1[2] << std::endl;

	std::cout << "s1의 세번째 위치의 문자: " << s1.at(2) << std::endl;

	std::cout << "s1의 첫번째 위치의 문자: " << s1.front() << std::endl;

	std::cout << "s1의 마지막 위치의 문자: " << s1.back() << std::endl;



	// C언어 형식의 문자열 얻기
	const char* pC1 = s1.c_str();
	const char* pC2 = s1.data();
	
	std::cout << "pC1: " << pC1 << std::endl;
	std::cout << "pC2: " << pC2 << std::endl;

	return 0;
}





