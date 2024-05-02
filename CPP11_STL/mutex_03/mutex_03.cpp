
#include <thread>
#include <mutex>
#include <iostream>

std::once_flag p_flag;

void Test()
{
	std::cout << "Test" << std::endl;
}

int main()
{
	for( int i = 0; i < 7; ++i )
	{
		std::call_once( p_flag, Test );
	}

	return 0;
}

