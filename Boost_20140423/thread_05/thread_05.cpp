
#include <iostream>
#include <boost/chrono/chrono.hpp>
#include <boost/thread/thread.hpp>

int main()
{
	std::cout << "sleep_for 테스트 시작" << std::endl;

	boost::chrono::seconds dura(3);
	boost::chrono::system_clock::time_point StartTime = boost::chrono::system_clock::now();

	boost::this_thread::sleep_for(dura);

	boost::chrono::system_clock::time_point EndTime = boost::chrono::system_clock::now();
	boost::chrono::seconds sec = boost::chrono::duration_cast<boost::chrono::seconds>(EndTime - StartTime);

	std::cout << "경과 시간(초)" << sec.count() << std::endl;


	std::cout << "sleep_until 테스트 시작" << std::endl;

	StartTime = boost::chrono::system_clock::now();
	boost::chrono::seconds dura_sec(5);

	boost::this_thread::sleep_until(StartTime + dura_sec);

	EndTime = boost::chrono::system_clock::now();
	sec = boost::chrono::duration_cast<boost::chrono::seconds>(EndTime - StartTime);

	std::cout << "경과 시간(초)" << sec.count() << std::endl;
	
	return 0;
}