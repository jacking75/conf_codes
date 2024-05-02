// √‚√≥: http://d.hatena.ne.jp/y_mazun/20130205/1360077844 


#include <boost/coroutine/all.hpp>
#include <iostream>

typedef boost::coroutines::coroutine<int> coroutine_type;

class Test{
public:
	Test(){ std::cout << "Test: constructor" << std::endl; }
	~Test(){ std::cout << "Test: destructor" << std::endl; }
};

void func(coroutine_type::push_type &yeild)
{
	Test t;

	std::cout << "Function: start" << std::endl;

	for (int i = 0; i < 3; i++){
		std::cout << "Function: yield " << i << std::endl;
		yeild(i);
	}

	std::cout << "Function: end" << std::endl;
}

int main()
{
	{
		std::cout << "Main: start" << std::endl;

		coroutine_type::pull_type c(func);

		while (c)
		{
			std::cout << "Main: get " << c.get() << std::endl;
			c();
		}

		std::cout << "Main: end" << std::endl;
	}

	return 0;
}
