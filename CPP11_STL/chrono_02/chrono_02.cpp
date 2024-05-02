
#include <chrono>
#include <iostream>
#include <cmath>


void Test()
{
	for ( long i = 0; i < 10000000; ++i )
	{
		std::sqrt( 123.456L );
	}
}

int main()
{
	std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();
	
	Test();

	std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();

 

	std::chrono::duration<double> DefaultSec = EndTime - StartTime;

	std::chrono::nanoseconds nano = EndTime - StartTime;
	std::chrono::microseconds micro = std::chrono::duration_cast<std::chrono::microseconds>(EndTime - StartTime);
	std::chrono::milliseconds mill	= std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - StartTime);
	std::chrono::seconds sec		= std::chrono::duration_cast<std::chrono::seconds>(EndTime - StartTime);
	std::chrono::minutes min		= std::chrono::duration_cast<std::chrono::minutes>(EndTime - StartTime);
	std::chrono::hours hour			= std::chrono::duration_cast<std::chrono::hours>(EndTime - StartTime);
	 

	std::cout << "Test() 함수를 수행하는 걸린 시간 : " << DefaultSec.count() << " default" << std::endl;
	std::cout << "Test() 함수를 수행하는 걸린 시간 : " << nano.count() << " nanoseconds" << std::endl;
	std::cout << "Test() 함수를 수행하는 걸린 시간 : " << micro.count() << " microseconds" << std::endl;
	std::cout << "Test() 함수를 수행하는 걸린 시간 : " << mill.count() << " milliseconds" << std::endl;
	std::cout << "Test() 함수를 수행하는 걸린 시간 : " << sec.count() << " seconds" << std::endl;
	std::cout << "Test() 함수를 수행하는 걸린 시간 : " << min.count() << " minutes" << std::endl;
	std::cout << "Test() 함수를 수행하는 걸린 시간 : " << hour.count() << " hour" << std::endl;
	
	return 0;
}


