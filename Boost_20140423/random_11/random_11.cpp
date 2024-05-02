
#include <random>
#include <boost/random.hpp>

int main()
{
	std::mt19937_64 rng1(3244);
		
	boost::random::triangle_distribution<> dist(165, 172, 180);

	for (int i = 0; i < 100; ++i)
	{
		auto result = dist(rng1);
		std::cout << result << std::endl;
	}

	return 0;
}


