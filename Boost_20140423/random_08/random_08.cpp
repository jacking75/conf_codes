
#include <boost/random.hpp>
#include <iostream>

int main()
{
	// -3 ~ 3 사이의 난수 생성
	boost::mt19937_64 rng1(3244);
	boost::random::uniform_int_distribution<__int64> dist1(-3, 3);
	boost::variate_generator<boost::mt19937_64&, boost::random::uniform_int_distribution<__int64>> rand(rng1, dist1);

	std::cout << "dist1의 최소 값: " << dist1.min() << std::endl;
	std::cout << "dist1의 최대 값: " << dist1.max() << std::endl;

	for (int i = 0; i < 7; ++i)
	{
		std::cout << rand() << std::endl;
	}
}

