// √‚√≥: http://faithandbrave.hateblo.jp/entry/20120802/1343891451

#include <iostream>
#include <boost/fusion/include/deque.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <boost/lambda/lambda.hpp>

namespace fusion = boost::fusion;
using boost::lambda::_1;


int main()
{
	fusion::deque<int, char, double> deq(1, 'a', 3.14);
	
	fusion::for_each(deq, std::cout << _1 << '\n');

	return 0;
}



