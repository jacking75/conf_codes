
#include <condition_variable>
#include <iostream>
#include <thread>


int main()
{
	std::mutex mtx_lock;
	std::condition_variable Cond;
	

	std::thread Thread1( [&] () 
		   {
			   for( int i = 1; i < 6; ++i )
			   {
					std::cout << "Thread 1 : " << i << std::endl;
			   }

			   Cond.notify_one();
		   } );


	std::thread Thread2( [&] () 
		   {
			   std::unique_lock<std::mutex> uniq_lock(mtx_lock);
			   Cond.wait( uniq_lock );

			   for( int i = 21; i < 26; ++i )
			   {
					std::cout << "Thread 2 : " << i << std::endl;
			   }

			   Cond.notify_one();
		   } );

	std::thread Thread3( [&] () 
		   {
			   std::unique_lock<std::mutex> uniq_lock(mtx_lock);
			   Cond.wait( uniq_lock );

			   for( int i = 31; i < 36; ++i )
			   {
					std::cout << "Thread 3 : " << i << std::endl;
			   }

			   Cond.notify_one();
		   } );


	Thread1.join();
	Thread2.join();
	Thread3.join();
	return 0;
}


//int main()
//{
//	std::mutex mtx_lock;
//	std::condition_variable Cond;
//	
//
//	std::thread Thread1( [&] () 
//		   {
//			   for( int i = 1; i < 11; ++i )
//			   {
//					std::cout << "Thread 1 : " << i << std::endl;
//			   }
//
//			   Cond.notify_one();
//		   } );
//
//
//	std::thread Thread2( [&] () 
//		   {
//			   std::unique_lock<std::mutex> uniq_lock(mtx_lock);
//			   Cond.wait( uniq_lock );
//
//			   for( int i = 21; i < 26; ++i )
//			   {
//					std::cout << "Thread 2 : " << i << std::endl;
//			   }
//		   } );
//
//
//	Thread1.join();
//	Thread2.join();
//	return 0;
//}

