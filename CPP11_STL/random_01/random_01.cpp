
#include <random>
#include <iostream>

int main()
{
	std::mt19937 mtRand;

	for( int i = 0; i < 7; ++i )
	{
		std::cout << mtRand() << std::endl;
	}

	return 0;
}

