// 출처: http://theboostcpplibraries.com/boost.coroutine#ex.coroutine_03

#include <boost/coroutine/all.hpp>
#include <tuple>
#include <string>
#include <iostream>

using boost::coroutines::coroutine;

void cooperative(coroutine<std::tuple<int, std::string>>::pull_type &source)
{
	std::cout << "cooperative first" << std::endl;

	std::cout << "source.get() 호출" << std::endl;
	auto args = source.get();
	std::cout << std::get<0>(args) << " " << std::get<1>(args) << '\n';
	
	std::cout << "source() 호출" << std::endl;
	source();

	std::cout << "source.get() 호출" << std::endl;
	args = source.get();
	std::cout << std::get<0>(args) << " " << std::get<1>(args) << '\n';

	std::cout << "cooperative end" << std::endl;
}

int main()
{
	std::cout << "main: sink 생성" << std::endl;
	coroutine<std::tuple<int, std::string>>::push_type sink{ cooperative };
	
	std::cout << "main: sink( 0, aaa) 호출" << std::endl;
	sink(std::make_tuple(0, "aaa"));
	
	std::cout << "main: sink(1, bbb) 호출" << std::endl;
	sink(std::make_tuple(1, "bbb"));
	
	std::cout << " main end" << std::endl;
	return 0;
}


