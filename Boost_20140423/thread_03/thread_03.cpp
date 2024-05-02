

#include <boost/thread/thread.hpp>
#include <iostream>

int main()
{
	int nThreadRunCount = 0;
	boost::thread Thread = boost::thread([&]()
	{
		for (int i = 0; i < 10; ++i)
		{
			++nThreadRunCount;
			std::cout << "Thread1 ID : " << Thread.get_id() << std::endl;
		}
	});

	while (nThreadRunCount < 3)
	{
	}

	Thread.detach();

	if (Thread.joinable())
	{
		std::cout << "join으로 스레드 종료 대기" << std::endl;
		Thread.join();
	}
	else
	{
		std::cout << "join 사용 불가" << std::endl;
	}
	
	return 0;
}
