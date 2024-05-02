#include <iostream>
#include <string>
#include <boost/algorithm/string/trim.hpp>

int main()
{
	{
		std::string s = "  abc   ";

		boost::algorithm::trim(s);
		std::cout << '[' << s << ']' << std::endl;
	}

	{
		const std::string s = "  abc   ";

		const std::string result = boost::algorithm::trim_copy(s);
		std::cout << '[' << result << ']' << std::endl;
	}


	{
		std::string s = "  abc   ";

		boost::algorithm::trim_left(s);
		std::cout << '[' << s << ']' << std::endl;
	}

	{
		const std::string s = "  abc   ";

		const std::string result = boost::algorithm::trim_left_copy(s);
		std::cout << '[' << result << ']' << std::endl;
	}


	{
		std::string s = "  abc   ";

		boost::algorithm::trim_right(s);
		std::cout << '[' << s << ']' << std::endl;
	}

	{
		const std::string s = "  abc   ";

		const std::string result = boost::algorithm::trim_right_copy(s);
		std::cout << '[' << result << ']' << std::endl;
	}
}