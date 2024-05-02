#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>

int main()
{
	boost::mutex mtx_lock;

	boost::thread Threads1([&]()
	{
		for (int i = 0; i < 5; ++i)
		{
			boost::lock_guard<boost::mutex> guard(mtx_lock);
			std::cout << "Thread Num : " << i << std::endl;
		}
	});


	boost::thread Threads2;
	Threads2 = boost::thread([&]()
	{
		for (int i = 10; i < 15; ++i)
		{
			boost::lock_guard<boost::mutex> guard(mtx_lock);
			std::cout << "Thread Num : " << i << std::endl;
		}
	});


	Threads1.join();
	Threads2.join();

	return 0;
}
