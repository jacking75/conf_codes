
#include <iostream>
#include <string>


int main()
{
	std::string s1("jacking");
	
	s1.resize(4);
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s1의 문자열 길이: " << s1.size() << std::endl;
	std::cout << "s1에서 메모리 재할당 없이 저장할 수 있는 크기: " << s1.capacity() << std::endl;

	s1.shrink_to_fit();
	std::cout << "s1에서 메모리 재할당 없이 저장할 수 있는 크기: " << s1.capacity() << std::endl;

	

	std::string s2("Test_shrink_to_fitdsdsdsdsds");
	
	std::cout << "s2의 문자열 길이: " << s2.size() << std::endl;
	s2.resize(15);
	std::cout << "s2의 문자열 길이: " << s2.size() << std::endl;
	std::cout << "s2에서 메모리 재할당 없이 저장할 수 있는 크기: " << s2.capacity() << std::endl;

	s2.shrink_to_fit();
	std::cout << "s2에서 메모리 재할당 없이 저장할 수 있는 크기: " << s2.capacity() << std::endl;

	return 0;
}



