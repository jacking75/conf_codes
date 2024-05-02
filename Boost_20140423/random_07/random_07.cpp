
#include <random>
#include <boost/random.hpp>

int main()
{
	std::mt19937_64 rng1(3244);

	boost::random::normal_distribution<> dist(173, 5);

	for (int i = 0; i < 100; ++i) 
	{
		auto result = dist(rng1);
		std::cout << result << std::endl;
	}
}


