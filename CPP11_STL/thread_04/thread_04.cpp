
#include <thread>
#include <iostream>
#include <mutex>

int main()
{
	// 동기화 객체. 다음에 자세히 설명하겠다.
	std::mutex mtx_lock;

	int nThreadRunCount1 = 0;
	std::thread Thread1;
	Thread1 = std::thread( [&] () 
		  {
			  ::_sleep(100); // 0.01초 대기
			  for( int i = 0; i < 5; ++i )
			  {
				  ++nThreadRunCount1;
			      mtx_lock.lock();
				  std::cout << "Thread1 ID : " << Thread1.get_id() << std::endl;
				  mtx_lock.unlock();
			   }
			} );
	

	int nThreadRunCount2 = 0;
	std::thread Thread2;
	Thread2 = std::thread( [&] () 
		  {
			  ::_sleep(100); // 0.01초 대기
			   for( int i = 0; i < 5; ++i )
			   {
				   ++nThreadRunCount2;
									   
				   mtx_lock.lock();
				   std::cout << "Thread2 ID : " << Thread2.get_id() << std::endl;
				   mtx_lock.unlock();
				}
		 } );
	
	
	// Thread1과 Thread2가 스레드 ID를 제대로 할당 받은 후 swap하기 위해서 일시 대기
	while( nThreadRunCount1 < 3 && nThreadRunCount2 < 3 )
	{
	}

	mtx_lock.lock();
	std::cout << "swap 1,2" << std::endl;
	mtx_lock.unlock();

	Thread1.swap( Thread2 );
	
	Thread1.join();
	Thread2.join();

	return 0;
}


