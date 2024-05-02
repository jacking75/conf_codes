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
			mtx_lock.lock();
			std::cout << "Thread1 Num : " << i << std::endl;
			mtx_lock.unlock();
		}
	});


	boost::thread Threads2;
	Threads2 = boost::thread([&]()
	{
		for (int i = 10; i < 15; ++i)
		{
			mtx_lock.lock();
			std::cout << "Thread2 Num : " << i << std::endl;
			mtx_lock.unlock();
		}
	});

	boost::thread Threads3 = boost::thread([&](int nParam)
	{
		for (int i = 20; i < 25; ++i)
		{
			mtx_lock.lock();
			std::cout << "Thread3 Num : " << i << std::endl;
			mtx_lock.unlock();
		}
	}, 4);


	if (Threads1.joinable())
		Threads1.join();

	if (Threads2.joinable())
		Threads2.join();

	if (Threads3.joinable())
		Threads3.join();

	return 0;
}

