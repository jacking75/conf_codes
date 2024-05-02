
#include <iostream>
#include <boost/numeric/interval.hpp>


int main()
{
	boost::numeric::interval<int> range1(0, 100);
	std::cout << boost::numeric::median(range1) << std::endl;
	std::cout << boost::numeric::width(range1) << std::endl;
	

	boost::numeric::interval<int> range2(6, 7);
	boost::numeric::interval<int> range3(4, 8);
	
	auto range_min = boost::numeric::min(range2, range3);

	std::cout << range_min.lower() << " ~ "
		<< range_min.upper() << std::endl;

	auto range_max = boost::numeric::max(range2, range3);
	
	std::cout << range_max.lower() << " ~ "
		<< range_max.upper() << std::endl;


	boost::numeric::interval<int> range4(-4, 8);
	
	auto range_abs = boost::numeric::abs(range4);
	
	std::cout << range_abs.lower() << " ~ "
		<< range_abs.upper() << std::endl;

	return 0;
}


