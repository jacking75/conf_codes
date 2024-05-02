// ��ó: http://d.hatena.ne.jp/osyo-manga/20140213/1392299962


#include <boost/functional/overloaded_function.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
#include <iostream>


std::string to_string(int n)
{
	return boost::lexical_cast<std::string>(n);
}

int to_int(std::string str)
{
	return boost::lexical_cast<int>(str);
}


int main()
{
	
	boost::overloaded_function<
		std::string(int),
		int(std::string)
	> multi(&to_string, &to_int);

	// �Լ� �������̵�� ���� �μ��� Ÿ�Կ� ���� ȣ�� �Լ��� ��������.
	std::cout << multi(10) + "-mami" << std::endl;
	std::cout << multi("42") * 2 << std::endl;

	return 0;
}