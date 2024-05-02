
#include <iostream>
#include <boost/random.hpp>

int main()
{
	boost::mt19937_64 rng1(time(0));
  
	// 30% 확률로 1000번 시도했을 때 성공 회수 얻기
	boost::random::binomial_distribution<> dist(1000, 0.3);

	int result = dist(rng1);
	std::cout << result << std::endl;

	return 0;
}


