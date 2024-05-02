#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	std::vector< int > Moneys;
	Moneys.push_back( 100 );
	Moneys.push_back( 4000 );
	Moneys.push_back( 50 );
	Moneys.push_back( 7 );

	int TotalMoney1 = 0;
	std::for_each( Moneys.begin(), Moneys.end(), [&TotalMoney1](int Money) {
					TotalMoney1 += Money;
					} );

	std::cout << "Total Money 1 : " << TotalMoney1 << std::endl;
	return 0;
}
