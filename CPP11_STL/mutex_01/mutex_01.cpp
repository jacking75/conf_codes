
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
				mtx_lock.lock();
				std::cout << "Thread1 Num : " << i << std::endl;
				mtx_lock.unlock();
		   }
	   } );


	std::thread Threads2;
	Threads2 = std::thread( [&] () 
	   {
		   for( int i = 10; i < 15; ++i )
		   {
				mtx_lock.lock();
				std::cout << "Thread2 Num : " << i << std::endl;
				mtx_lock.unlock();
		   }
	   } );

	std::thread Threads3 = std::thread( [&] ( int nParam ) 
	   { 
		 for( int i = 20; i < 25; ++i )
		 {
			 mtx_lock.lock();
			 std::cout << "Thread3 Num : " << i << std::endl;
			 mtx_lock.unlock();
		 }
	   }, 4 );


	if(Threads1.joinable())
		Threads1.join();
	
	if(Threads2.joinable())
		Threads2.join();

	if(Threads3.joinable())
		Threads3.join();

	return 0;
}

