
#include <iostream>
#include <boost/numeric/interval.hpp>


int main()
{
	boost::numeric::interval<int> range1(0, 100);
	boost::numeric::interval<int> range2(30, 120);

	boost::numeric::interval<int> new_range1 = range1 + range2;

	std::cout << new_range1.lower() << " ~ "
		<< new_range1.upper() << std::endl;


	boost::numeric::interval<int> range3(10, 400);
	range3 += range2;

	std::cout << range3.lower() << " ~ "
		<< range3.upper() << std::endl;


	boost::numeric::interval<int> range4(0, 100);
	range4 += 1;

	std::cout << range4.lower() << " ~ "
		<< range4.upper() << std::endl;

	return 0;
}




