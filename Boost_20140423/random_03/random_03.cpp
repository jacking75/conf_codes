
#include <boost/nondet_random.hpp>
#include <iostream>

int main()
{
	boost::random_device rng;

	for (int i = 0; i < 7; ++i) 
	{
    	auto result = rng();
		std::cout << result << std::endl;
	}
}

