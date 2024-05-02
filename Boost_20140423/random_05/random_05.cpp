
#include <boost/random.hpp>
#include <iostream>

int main() 
{
	boost::mt19937_64 rng1(3244);

	boost::random::bernoulli_distribution<> dist(0.7);

	int nSuccess = 0;
	int nFail = 0;

	for (int i = 0; i < 100; ++i) 
	{
		bool result = dist(rng1);

		if(result)
			++nSuccess;
		else
			++nFail;
	}


	std::cout << "¼º°ø È½¼ö: " << nSuccess << ",  ½ÇÆÐ È½¼ö: " << nFail << std::endl;

	return 0;
}

