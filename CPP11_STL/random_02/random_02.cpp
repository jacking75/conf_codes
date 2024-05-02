
#include <random>
#include <iostream>
#include <chrono>

int main()
{
	auto curTime = std::chrono::system_clock::now(); 
	auto duration = curTime.time_since_epoch();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

	std::mt19937 mtRand(millis);

	for( int i = 0; i < 7; ++i )
	{
		std::cout << mtRand() << std::endl;
	}

	return 0;
}

