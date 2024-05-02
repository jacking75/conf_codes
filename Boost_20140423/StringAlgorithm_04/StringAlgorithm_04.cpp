#include <boost/algorithm/string.hpp> 
#include <locale> 
#include <iostream> 

int main()
{
	{
		std::string s = "Hello Boost, Hello C++11";
		boost::iterator_range<std::string::iterator> r = boost::algorithm::find_first(s, "Hello");
		std::cout << r << std::endl;
		std::cout << r.begin() - s.begin() << " ~ " << r.end() - s.begin() << std::endl;

		

		r = boost::algorithm::find_nth(s, "Hello", 0);
		std::cout << r << std::endl;
		std::cout << r.begin() - s.begin() << " ~ " << r.end() - s.begin() << std::endl;

		r = boost::algorithm::find_nth(s, "Hello", 1);
		std::cout << r << std::endl;
		std::cout << r.begin() - s.begin() << " ~ " << r.end() - s.begin() << std::endl;


		r = boost::algorithm::find_head(s, 4);
		std::cout << r << std::endl;

		r = boost::algorithm::find_tail(s, 4);
		std::cout << r << std::endl;
	}

	{
		std::cout << "wstring" << std::endl;
		std::wstring s = L"안녕 Boost, 안녕 C++11";
		boost::iterator_range<std::wstring::iterator> r = boost::algorithm::find_first(s, L"안녕");
		std::cout << r.begin() - s.begin() << " ~ " << r.end() - s.begin() << std::endl;
	}

	return 0;
}
