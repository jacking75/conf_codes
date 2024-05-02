#include <iostream>

int main()
{
	auto func = []( int n ) { std::cout << "Number : " << n << std::endl; };

	func( 333 );
	func( 7777 );

	return 0;
}
