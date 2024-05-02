
#include <iostream>
#include <boost/utility/value_init.hpp>

struct X 
{
	boost::initialized<int> NumValue;
	boost::initialized<bool> IsOK;
};

int main()
{
	X x;

	// �б�
	std::cout << x.NumValue.data() << std::endl;
	std::cout << x.IsOK.data() << std::endl;

	// ����
	x.NumValue.data() = 1;
	x.IsOK.data() = true;

	std::cout << x.NumValue.data() << std::endl;
	std::cout << x.IsOK.data() << std::endl;

	// ����/�б� ���� 2
	get(x.NumValue) = 2;
	std::cout << x.NumValue << std::endl;

	return 0;
}

