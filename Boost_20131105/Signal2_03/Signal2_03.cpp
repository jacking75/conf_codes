// ��ȯ �� Ŀ���͸���¡
#include <iostream>
#include <numeric>
#include <boost/signals2/signal.hpp>

// ���ӵ� ������ �Լ��� ��ȯ ���� ��踦 ���Ѵ�
 template <typename T>
struct custom_result_value
{
	typedef T result_type;
	
	template <typename InputIterator> 
	result_type operator()(InputIterator first, InputIterator last) const
	{
    	if( first == last ) {
        	return result_type();
    	}
    	return std::accumulate(first, last, 0);
	}
};


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
	boost::signals2::signal<int(int, int), custom_result_value<int> > sig;
	
	sig.connect(&add);
	sig.connect(&minus);
	sig.connect(&multiply);
	sig.connect(&divide);

	std::cout << sig(10, 2) << std::endl;

	return 0;
}
