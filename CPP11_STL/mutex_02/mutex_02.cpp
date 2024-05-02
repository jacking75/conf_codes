
#include <thread>
#include <iostream>
#include <mutex>

int main()
{
	std::mutex mtx_lock;

	std::thread Threads1( [&] () 
	   {
		   for( int i = 0; i < 5; ++i )
		   {
				std::lock_guard<std::mutex> guard(mtx_lock);
				std::cout << "Thread Num : " << i << std::endl;
		   }
	   } );


	std::thread Threads2;
	Threads2 = std::thread( [&] () 
	   {
		   for( int i = 10; i < 15; ++i )
		   {
				std::lock_guard<std::mutex> guard(mtx_lock);
				std::cout << "Thread Num : " << i << std::endl;
		   }
	   } );


	Threads1.join();
	Threads2.join();
	
	return 0;
}

