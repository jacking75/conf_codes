
#include <iostream>
#include <string>


int main()
{
	std::string s1("jacking");
	
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s1의 문자열 길이: " << s1.size() << std::endl;
	std::cout << "s1에서 메모리 재할당 없이 저장할 수 있는 크기: " << s1.capacity() << std::endl;

	s1.resize(4);
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s1의 문자열 길이: " << s1.size() << std::endl;
	std::cout << "s1에서 메모리 재할당 없이 저장할 수 있는 크기: " << s1.capacity() << std::endl;

	s1.resize(16);
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s1의 문자열 길이: " << s1.size() << std::endl;
	std::cout << "s1에서 메모리 재할당 없이 저장할 수 있는 크기: " << s1.capacity() << std::endl;

	s1.clear();
	std::cout << "s1: " << s1 << std::endl;

	std::cout << "s1 공백 여부: " << s1.empty() << std::endl;
	
	return 0;
}

