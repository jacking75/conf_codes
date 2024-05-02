
#include <iostream>
#include <boost/numeric/interval.hpp>

int main()
{
	auto range1 = boost::numeric::hull(0, 100);
	auto range2 = boost::numeric::hull(2, 2);
	
	std::cout << "range1�� ��Ҵ� �ϳ��ΰ�? " << boost::numeric::singleton(range1) << std::endl;
	std::cout << "range2�� ��Ҵ� �ϳ��ΰ�? " << boost::numeric::singleton(range2) << std::endl;
	
	return 0;
}
