#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <iostream>


int main()
{
	boost::mutex mtx_lock;
	boost::condition_variable Cond;


	boost::thread Thread1([&]()
	{
		for (int i = 1; i < 6; ++i)
		{
			std::cout << "Thread 1 : " << i << std::endl;
		}

		Cond.notify_one();
	});


	boost::thread Thread2([&]()
	{
		boost::unique_lock<boost::mutex> uniq_lock(mtx_lock);
		Cond.wait(uniq_lock);

		for (int i = 21; i < 26; ++i)
		{
			std::cout << "Thread 2 : " << i << std::endl;
		}

		Cond.notify_one();
	});

	boost::thread Thread3([&]()
	{
		boost::unique_lock<boost::mutex> uniq_lock(mtx_lock);
		Cond.wait(uniq_lock);

		for (int i = 31; i < 36; ++i)
		{
			std::cout << "Thread 3 : " << i << std::endl;
		}

		Cond.notify_one();
	});


	Thread1.join();
	Thread2.join();
	Thread3.join();
	return 0;
}