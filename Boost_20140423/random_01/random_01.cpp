

#include <boost/random.hpp>
#include <iostream>

int main()
{
	boost::mt19937 mtRand;

	for (int i = 0; i < 100; ++i)
	{
		std::cout << mtRand() << std::endl;
	}

	return 0;
}

