
#include <iostream>
#include <string>
#include <boost/algorithm/string/predicate.hpp> // iends_with


int main()
{
	{
		const std::string filename = "example.cpp";

		bool result = boost::algorithm::iends_with(filename, ".cpp");
		std::cout << std::boolalpha << result << std::endl;
	}

	{
		const std::string config_file = "<config >";
		const std::string text_file = "config";

		bool result = boost::algorithm::starts_with(config_file, "<config");
		std::cout << std::boolalpha << result << std::endl;

		result = boost::algorithm::starts_with(text_file, "<config");
		std::cout << std::boolalpha << result << std::endl;
	}
}