
#include <iostream>
#include <boost/utility/value_init.hpp>

struct X 
{
	boost::initialized<int> NumValue;
	boost::initialized<bool> IsOK;
};

int main()
{
	X x;

	// 읽기
	std::cout << x.NumValue.data() << std::endl;
	std::cout << x.IsOK.data() << std::endl;

	// 쓰기
	x.NumValue.data() = 1;
	x.IsOK.data() = true;

	std::cout << x.NumValue.data() << std::endl;
	std::cout << x.IsOK.data() << std::endl;

	// 쓰기/읽기 버전 2
	get(x.NumValue) = 2;
	std::cout << x.NumValue << std::endl;

	return 0;
}

