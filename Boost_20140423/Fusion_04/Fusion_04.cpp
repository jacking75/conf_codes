// √‚√≥: https://sites.google.com/site/boostjp/tips/tuple

#include <iostream>
#include <string>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/vector_tie.hpp>
#include <boost/fusion/include/ignore.hpp>

namespace fusion = boost::fusion;

int main()
{
	const fusion::vector<int, char, std::string> v(1, 'a', "Hello");

	int n;
	std::string s;
	fusion::vector_tie(n, fusion::ignore, s) = v;

	std::cout << n << std::endl;
	std::cout << s << std::endl;

	return 0;
}


