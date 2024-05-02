
#include <thread>
#include <mutex>
#include <iostream>

#define  thread_local __declspec(thread)

thread_local int nCount = 0;
std::mutex mtx_lock;

void Test()
{
	for( int i = 0; i < 10; ++i )
	{
		++nCount;
	}

	std::lock_guard<std::mutex> guard(mtx_lock);
	std::cout << "Thread ID: " << std::this_thread::get_id() << " nCount: " << nCount << std::endl; 
}

int main()
{
	std::thread Thread1, Thread2, Thread3;
	
	Thread1 = std::thread( [] () { Test(); } );
	Thread2 = std::thread( [] () { Test(); } );
	Thread3 = std::thread( [] () { Test(); } );

	Thread1.join();
	Thread2.join();
	Thread3.join();
	
	return 0;
}


