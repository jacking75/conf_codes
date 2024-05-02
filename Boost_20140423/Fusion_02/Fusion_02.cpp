
#include <iostream>
#include <string>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/include/at_c.hpp>

namespace fusion = boost::fusion;

int main()
{
	const auto v = fusion::make_vector(123, "Hello!", 4.56f);

	std::cout << fusion::at_c<0>(v) << std::endl;
	std::cout << fusion::at_c<1>(v) << std::endl;
	std::cout << fusion::at_c<2>(v) << std::endl;

	return 0;
}



