
#include <iostream>
#include <string>


int main()
{
	std::string s1("twitter:");
	std::cout << "s1: " << s1 << std::endl;
	
	std::string s2("@jacking75");
	std::cout << "s2: " << s2 << std::endl;

	// 문자열 결합
	std::string s3 = s1 + s2;
	std::cout << "s3=s1+s2: " << s3 << std::endl;

	std::string s4 = s1 + "@jacking75";
	std::cout << "s4=s1+@jacking75: " << s4 << std::endl;

	std::string s5 = s1.append(s2);
	std::cout << "s5=s1.append(s2): " << s5 << std::endl;

	// 문자열 삽입
	std::string s6("C++STL");
	s6.insert(3, "11 ");
	std::cout << "s6: " << s6 << std::endl;

	// 문자열 삭제
	s6.erase(6, 3);
	std::cout << "s6: " << s6 << std::endl;

	// 끝에 문자 추가
	std::string s7("Boos");
	std::cout << "s7: " << s7 << std::endl;
	s7.push_back('t');
	std::cout << "s7: " << s7 << std::endl;

	// 끝 문자 삭제
	s7.pop_back();
	std::cout << "s7: " << s7 << std::endl;

	// 문자열 바꾸기
	std::string s8("Network-Winsock");
	std::cout << "s8: " << s8 << std::endl;
	s8.replace(8,7,"Boost.Asio");
	std::cout << "s8: " << s8 << std::endl;

	// 교환하기
	std::string s9("Boost.Asio");
	std::string s10("C++11 STL");
	std::cout << "s9: " << s9 << std::endl;
	std::cout << "s10: " << s10 << std::endl;

	s9.swap(s10);
	std::cout << "s9: " << s9 << std::endl;
	std::cout << "s10: " << s10 << std::endl;
	
	return 0;
}


