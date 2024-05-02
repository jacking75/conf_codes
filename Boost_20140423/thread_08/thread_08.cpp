
#include <boost/thread/thread.hpp>
#include <boost/thread/once.hpp>
#include <iostream>

boost::once_flag flag = BOOST_ONCE_INIT;

void Test()
{
	std::cout << "Test" << std::endl;
}

int main()
{
	for (int i = 0; i < 7; ++i)
	{
		boost::call_once(Test, flag);
	}

	return 0;
}
