
#include <iostream>
#include <boost/numeric/interval.hpp>


int main()
{
	auto range1 = boost::numeric::hull(0, 100);
	//auto range2 = boost::numeric::hull(20.5, 120);
	auto range2 = boost::numeric::hull(20.5, 120.0);
	
	std::cout << range1.lower() << " ~ "
		<< range1.upper() << std::endl;

	std::cout << range2.lower() << " ~ "
		<< range2.upper() << std::endl;

	return 0;
}

