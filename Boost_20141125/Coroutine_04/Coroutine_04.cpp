// 출처: http://theboostcpplibraries.com/boost.coroutine#ex.coroutine_02

#include <boost/coroutine/all.hpp>
#include <functional>
#include <iostream>

using boost::coroutines::coroutine;

void cooperative(coroutine<int>::push_type &sink, int i)
{
	std::cout << "cooperative first" << std::endl;

	int j = i;
	sink(++j);
	sink(++j);

	std::cout << "cooperative end" << std::endl;
}

int main()
{
	using std::placeholders::_1;
	
	std::cout << "source 생성" << std::endl;
	coroutine<int>::pull_type source{ std::bind(cooperative, _1, 0) };
	
	std::cout << "source.get() 호출" << std::endl;
	std::cout << source.get() << std::endl;
	std::cout << "source() 호출" << std::endl;
	source();

	std::cout << "source.get() 호출" << std::endl;
	std::cout << source.get() << std::endl;
	std::cout << "source() 호출" << std::endl;
	source();

	return 0;
}