
#include <random>
#include <iostream>

int main()
{
	std::random_device rng;

	for (int i = 0; i < 7; ++i) 
	{
    	auto result = rng();
		std::cout << result << std::endl;
	}
}

