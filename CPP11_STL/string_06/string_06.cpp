
#include <iostream>
#include <string>


int main()
{
	std::string s1("C++11 STL");
	std::string s2("C++11 STL");
	
	if( s1.compare(s2) == 0 )
	{
		std::cout << "s1과 s2는 같다" << std::endl;
	}
	else
	{
		std::cout << "s1과 s2는 다르다" << std::endl;
	}
	
	if( s1 == s2 )
	{
		std::cout << "s1과 s2는 같다" << std::endl;
	}
	else
	{
		std::cout << "s1과 s2는 다르다" << std::endl;
	}
		
	return 0;
}


