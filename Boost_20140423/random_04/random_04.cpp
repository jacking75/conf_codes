
#include <boost/random.hpp>
#include <iostream>

int main()
{
	// -3 ~ 3 ������ ���� ����
	boost::mt19937_64 rng1(3244);
	boost::random::uniform_int_distribution<__int64> dist1(-3, 3);

	std::cout << "dist1�� �ּ� ��: " << dist1.min() << std::endl;
	std::cout << "dist1�� �ִ� ��: " << dist1.max() << std::endl;

	for( int i = 0; i < 7; ++i )
	{
		std::cout << dist1(rng1) << std::endl;
	}

	std::cout << std::endl;


	// 0.0 ~ 1.0 ������ ���� ����
	boost::mt19937 rng2;
	boost::random::uniform_real_distribution<double> dist2(0.0, 1.0);

	std::cout << "dist1�� �ּ� ��: " << dist2.min() << std::endl;
	std::cout << "dist1�� �ִ� ��: " << dist2.max() << std::endl;

	for( int i = 0; i < 5; ++i )
	{
		std::cout << dist2(rng2) << std::endl;
	}

	return 0;
}


