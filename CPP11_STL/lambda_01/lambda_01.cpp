#include <iostream>

int main()
{
	auto func = [] { std::cout << "Hello, TechDay!" << std::endl; };

	func();

	return 0;
}
