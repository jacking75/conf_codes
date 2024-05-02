// 반환 값

#include <iostream>
#include <boost/signals2/signal.hpp>

int add(int x, int y)
{
	return x + y;
}

int minus(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}


int main()
{
	boost::signals2::signal<int(int, int)> sig;
	boost::signals2::signal<int(int, int)> non_connect_sig;
	
	sig.connect(&add);
	sig.connect(&minus);
	sig.connect(&multiply);
	sig.connect(&divide);
	
	// boost::optional<int>가 반환 된다
	std::cout << *sig(10, 2) << std::endl;
	
	// 유효하지 않은 호출
	const boost::optional<int> non_connect_result = non_connect_sig(10, 2);
	
	if(!non_connect_result) {
    	std::cout << "invalid value" << std::endl;
	}

	return 0;
}
