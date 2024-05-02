
#include <boost/thread/thread.hpp>
#include <iostream>

class ThreadPara 
{
public:
	void func()
	{
		for (int i = 0; i < 5; ++i)
		{
			std::cout << "ThreadPara Num : " << i << std::endl;
		}
	}
};

int main()
{
	boost::thread Thread1( [] () 
		   {
			   for( int i = 0; i < 5; ++i )
			   {
				std::cout << "Thread1 Num : " << i << std::endl;
			   }
	           } );
	Thread1.join();


	boost::thread Thread2;
	Thread2 = boost::thread([]()
		   {
			   for( int i = 10; i < 15; ++i )
			   {
				std::cout << "Thread2 Num : " << i << std::endl;
			   }
		    } );
	Thread2.join();


	boost::thread Thread3 = boost::thread([](int nParam)
		   { 
			 for( int i = 20; i < 25; ++i )
			 {
			    std::cout << "Thread3 Parameter : " << nParam << std::endl;
			 }
		       }, 4 );
	Thread3.join();

	ThreadPara thread_para;
	boost::thread Thread4(&ThreadPara::func, &thread_para);
	Thread4.join();

	return 0;
}

