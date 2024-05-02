#include <iostream>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>


boost::mutex mtx_lock;

void run(const char thr_name)
{
	for (int i = 0; i < 3; ++i)
	{
		{
			boost::lock_guard<boost::mutex> guard(mtx_lock);
			std::cout << "Thread-" << thr_name << ": No." << i << std::endl;
		}
	}
}

int main()
{
	const char chs[] = { 'A', 'B', 'C', 'D' };
	const int NUM_THREAD = 4;

	boost::thread_group thr_grp;

	for (int i = 0; i < NUM_THREAD; ++i)
	{
		thr_grp.create_thread(boost::bind(&run, chs[i]));
	}

	thr_grp.join_all();

	return 0;
}