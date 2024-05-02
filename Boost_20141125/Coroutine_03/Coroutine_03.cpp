﻿
#include <iostream>
#include <boost/coroutine/all.hpp>

typedef boost::coroutines::coroutine<void> coroutine;

void g(coroutine::push_type& caller)
{
	std::cout << 2 << std::endl;
	caller();
	std::cout << 4 << std::endl;
}

int main()
{
	coroutine::pull_type c1([&](coroutine::push_type& caller) {
		std::cout << 1 << std::endl;
		caller();
		std::cout << 3 << std::endl;
	});

	coroutine::pull_type c2(g);

	while (c1 && c2)
	{
		c1();
		c2();
	}

	return 0;
}
