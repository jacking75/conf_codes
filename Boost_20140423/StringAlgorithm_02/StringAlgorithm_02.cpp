#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>




int main()
{
	int i = 0;
	const std::string s1 = "abc,123,xyz";

	std::vector<std::string> result1;
	boost::algorithm::split(result1, s1, boost::is_any_of(",")); 
		
	for (auto token : result1)
	{
		++i;
		std::cout << i << ": " << token << std::endl;
	}
	std::cout << std::endl;

	
	const std::string s2 = "abc 123 xyz  g";
	
	std::vector<std::string> result2;
	boost::algorithm::split(result2, s2, boost::is_space());

	i = 0;
	for (auto token : result2)
	{
		++i;
		std::cout << i << ": " << token << std::endl;
	}
	std::cout << std::endl;

	
	std::vector<std::string> result3;
	boost::algorithm::split(result3, s2, boost::is_space(), boost::token_compress_on);

	i = 0;
	for (auto token : result3)
	{
		++i;
		std::cout << i << ": " << token << std::endl;
	}
	std::cout << std::endl;

	
	const std::vector<std::string> string_vec = { "a", "b", "c" };

	const std::string join_string = boost::algorithm::join(string_vec, ",");
	std::cout << join_string << std::endl;
	
	return 0;
}