#include <iostream>
#include <string>

int main()
{
	// 문자열 사용 없이 생성
	std::string s1;
	std::cout << "s1 : " << s1 << std::endl;


	// 문자열 사용
	std::string s2 = "hello";
    std::cout << "s2 : " << s2 << std::endl;

    std::cout << "s3 : " << std::string("hello") << std::endl;


    // 문자열의 일부만 사용 
    // 문자열의 두개만 s4에 복사
    std::string s4("hello", 2);
    std::cout << "s4 : " << s4 << std::endl;

    // 문자열의 2번째 위치에서 8문자까지만 s5에 복사
    std::string s5("Game is Fun", 1, 8);
    std::cout << "s5 : " << s5 << std::endl;

    std::string s6(s5, 0, 3);
    std::cout << "s6 : " << s6 << std::endl;


    // 문자를 지정 횟수만큼 복사
    std::string s7(7, 'c');
    std::cout << "s7 : " << s7 << std::endl;
  

    // 반복자를 사용하여 문자열 복사
    std::string s8(s2.begin(), s2.end());
    std::cout << "s8 : " << s8 << std::endl;

	return 0;
}



