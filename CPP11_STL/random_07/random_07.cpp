
#include <random>
#include <iostream>

int main()
{
	std::mt19937_64 rng1(3244);

	std::normal_distribution<> dist(173, 5);

	for (int i = 0; i < 100; ++i) 
	{
		int result = dist(rng1);
		std::cout << result << std::endl;
	}
}


