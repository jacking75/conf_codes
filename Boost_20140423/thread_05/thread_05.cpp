
#include <iostream>
#include <boost/chrono/chrono.hpp>
#include <boost/thread/thread.hpp>

int main()
{
	std::cout << "sleep_for �׽�Ʈ ����" << std::endl;

	boost::chrono::seconds dura(3);
	boost::chrono::system_clock::time_point StartTime = boost::chrono::system_clock::now();

	boost::this_thread::sleep_for(dura);

	boost::chrono::system_clock::time_point EndTime = boost::chrono::system_clock::now();
	boost::chrono::seconds sec = boost::chrono::duration_cast<boost::chrono::seconds>(EndTime - StartTime);

	std::cout << "��� �ð�(��)" << sec.count() << std::endl;


	std::cout << "sleep_until �׽�Ʈ ����" << std::endl;

	StartTime = boost::chrono::system_clock::now();
	boost::chrono::seconds dura_sec(5);

	boost::this_thread::sleep_until(StartTime + dura_sec);

	EndTime = boost::chrono::system_clock::now();
	sec = boost::chrono::duration_cast<boost::chrono::seconds>(EndTime - StartTime);

	std::cout << "��� �ð�(��)" << sec.count() << std::endl;
	
	return 0;
}