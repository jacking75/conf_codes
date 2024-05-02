
#include <iostream>
#include <boost/numeric/interval.hpp>


int main()
{
	boost::numeric::interval<int> valid_range(0, 100);
	
	int input = 0;

	do
	{
		std::cout << valid_range.lower() << " ~ " 
			      << valid_range.upper() << 
				  " 사이의 값을 입력해 주세요" << std::endl;

		std::cin >> input;

	} while (boost::numeric::in(input, valid_range) == false);
	
	return 0;
}


