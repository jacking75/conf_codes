#include <boost/random.hpp>
#include <iostream>

int main()
{
	boost::mt19937 rng1(time(0));
	boost::random::random_number_generator<boost::mt19937, int> rand(rng1);

	for (int i = 0; i < 7; ++i)
	{
		std::cout << rand(30) << std::endl;
	}

	for (int i = 0; i < 7; ++i)
	{
		std::cout << rand(10) << std::endl;
	}
}



