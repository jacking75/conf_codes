#include <iostream>
#include <boost/scope_exit.hpp>


// C++11
void f()
{
	std::cout << "1 -------" << std::endl;
	int x = 1;
	int y = 1;
		
	std::cout << x << std::endl;
	std::cout << y << std::endl;

	BOOST_SCOPE_EXIT_ALL(&x, &y) {
		std::cout << "3 -------" << std::endl;
		x = 3;
		y = 3;
		
		std::cout << x << std::endl;
		std::cout << y << std::endl;
	};

	std::cout << "2 -------" << std::endl;
	x = 2;
	y = 2;
	
	std::cout << x << std::endl;
	std::cout << y << std::endl;
}


int main()
{
	f();
}