
#include <iostream>
#include <string>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/algorithm.hpp>

struct Double
{
	template<typename T>
	void operator()(T& x) const
	{
		x = x + x;
	}
};

int main()
{
	boost::fusion::vector<int, std::string, float> fusion1(123, "Hello!", 4.56);
	
	boost::fusion::for_each(fusion1, Double());

	std::cout << boost::fusion::at_c<0>(fusion1) << std::endl;
	std::cout << boost::fusion::at_c<1>(fusion1) << std::endl;
	std::cout << boost::fusion::at_c<2>(fusion1) << std::endl;

	return 0;
}



