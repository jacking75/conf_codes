
#include <iostream>
#include <string>
#include <boost/algorithm/string/replace.hpp>

int main()
{
	{
		std::string s = "Hello Boost, Hello C++11";

		boost::algorithm::replace_all(s, "Hello", "Good");
		std::cout << s << std::endl;
	}

	{
		std::string s = "Hello Boost, Hello C++11";

		const std::string result = boost::algorithm::replace_all_copy(s, "Hello", "Good");
		std::cout << result << std::endl;
	}
}