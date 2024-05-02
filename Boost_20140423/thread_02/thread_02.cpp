#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>


int main()
{
	std::cout << "main() 스레드 ID: " << boost::this_thread::get_id() << std::endl;


	// 동기화 객체. 
	boost::mutex mtx_lock;

	int nThreadRunCount1 = 0;
	boost::thread Thread1;
	Thread1 = boost::thread([&]()
	{
		::_sleep(100); // 0.01초 대기
		for (int i = 0; i < 5; ++i)
		{
			++nThreadRunCount1;
			mtx_lock.lock();
			std::cout << "Thread1 ID : " << Thread1.get_id() << std::endl;
			std::cout << "Thread1 this_thread::get_id(): " << boost::this_thread::get_id() << std::endl;
			mtx_lock.unlock();
		}
	});


	int nThreadRunCount2 = 0;
	boost::thread Thread2;
	Thread2 = boost::thread([&]()
	{
		::_sleep(100); // 0.01초 대기
		for (int i = 0; i < 5; ++i)
		{
			++nThreadRunCount2;

			mtx_lock.lock();
			std::cout << "Thread2 ID : " << Thread2.get_id() << std::endl;
			std::cout << "Thread2 ID(Native) : " << (int)Thread2.native_handle() << std::endl;
			mtx_lock.unlock();
		}
	});


	// Thread1과 Thread2가 스레드 ID를 제대로 할당 받은 후 swap하기 위해서 일시 대기
	while (nThreadRunCount1 < 3 && nThreadRunCount2 < 3)
	{
	}

	mtx_lock.lock();
	std::cout << "swap 1,2" << std::endl;
	mtx_lock.unlock();

	Thread1.swap(Thread2);

	Thread1.join();
	Thread2.join();

	return 0;
}




