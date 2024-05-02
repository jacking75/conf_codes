
#include <iostream>
#include <boost/random.hpp>

int main()
{
	std::size_t seed = 0;

	boost::mt19937 gen(seed);
	boost::random::uniform_int_distribution<> dist(0, 10);

	for (int i = 0; i < 3; ++i) 
	{
		std::cout << dist(gen) << std::endl;
	}

	std::cout << "-- seed 재설정 --" << std::endl;
	
	gen.seed(seed); 

	for (int i = 0; i < 3; ++i) {
		std::cout << dist(gen) << std::endl;
	}

	return 0;
}

