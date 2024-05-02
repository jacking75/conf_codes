#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	std::vector< int > Moneys;
	Moneys.push_back( 100 );
	Moneys.push_back( 4000 );
	Moneys.push_back( 1001 );
	Moneys.push_back( 7 );

	int TotalMoney1 = 0;
	int TotalBigMoney = 0;

	// Money가 1000 보다 크면 TotalBigMoney에 누적한다.
	std::for_each(Moneys.begin(), Moneys.end(), [&](int Money) {
						TotalMoney1 += Money;
						if( Money > 1000 ) TotalBigMoney += Money;
					});

	std::cout << "Total Money 1 : " << TotalMoney1 << std::endl;
	std::cout << "Total Big Money : " << TotalBigMoney << std::endl;

	return 0;
}

