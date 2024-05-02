#include <boost/algorithm/string.hpp> 
#include <locale> 
#include <iostream> 

int main()
{
	std::string s = "Hello Boost, Hello C++11";
	std::cout << "s:" << s << std::endl;
	std::cout << std::endl;

	std::cout << boost::algorithm::erase_first_copy(s, "Boost") << std::endl;
	std::cout << boost::algorithm::erase_nth_copy(s, "Hello", 1) << std::endl;
	std::cout << boost::algorithm::erase_last_copy(s, "Hello") << std::endl;
	std::cout << boost::algorithm::erase_all_copy(s, "Hello") << std::endl;
	std::cout << boost::algorithm::erase_head_copy(s, 5) << std::endl;
	std::cout << boost::algorithm::erase_tail_copy(s, 8) << std::endl;
	std::cout << std::endl;

	std::cout << "s:" << s << std::endl;
}