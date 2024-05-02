
#include <thread>
#include <iostream>

int main()
{
	int nThreadRunCount = 0;
	std::thread Thread = std::thread( [&] () 
			{
				for( int i = 0; i < 10; ++i )
				{
					++nThreadRunCount;
					std::cout << "Thread1 ID : " << Thread.get_id() << std::endl;
				}
		     } );

	while( nThreadRunCount < 3 )
	{
	}

	Thread.detach();

	if( Thread.joinable() )
	{
		Thread.join();
	}

	return 0;
}

