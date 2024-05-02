// √‚√≥: https://sites.google.com/site/boostjp/tips/scope_guard

#include <iostream>
#include <boost/scope_exit.hpp>

struct X 
{
	int value;

	void foo()
	{
		value = 0;

		BOOST_SCOPE_EXIT((&value)) {
			value = 2;
		} BOOST_SCOPE_EXIT_END

		value = 1;
	}
};

int main()
{
	X x;
	x.foo();

	std::cout << x.value << std::endl;

	return 0;
}