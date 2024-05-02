
#include <iostream>
#include <boost/numeric/interval.hpp>


int main()
{
	boost::numeric::interval<int> range1(0, 100);
	boost::numeric::interval<int> range2(30, 120);

	auto new_range1 = boost::numeric::intersect(range1, range2);

	std::cout << new_range1.lower() << " ~ "
		<< new_range1.upper() << std::endl;

	return 0;
}

