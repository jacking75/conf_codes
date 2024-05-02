
#include <random>
#include <iostream>

int main()
{
	// -3 ~ 3 사이의 난수 생성
	std::mt19937_64 rng1(3244);
	std::uniform_int_distribution<__int64> dist1(-3, 3);

	std::cout << "dist1의 최소 값: " << dist1.min() << std::endl;
	std::cout << "dist1의 최대 값: " << dist1.max() << std::endl;

	for( int i = 0; i < 7; ++i )
	{
		std::cout << dist1(rng1) << std::endl;
	}

	std::cout << std::endl;


	// 0.0 ~ 1.0 사이의 난수 생성
	std::mt19937 rng2;
	std::uniform_real_distribution<double> dist2(0.0, 1.0);

	for( int i = 0; i < 5; ++i )
	{
		std::cout << dist2(rng2) << std::endl;
	}

	return 0;
}


