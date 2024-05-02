// ��ó: https://sites.google.com/site/boostjp/tips/variant

#include <iostream>
#include <string>
#include <boost/variant.hpp>

struct var_printer : boost::static_visitor<void> {
	void operator()(int x) const
	{
		std::cout << x << std::endl;
	}

	void operator()(std::string& s) const
	{
		std::cout << s << std::endl;
	}

	void operator()(double x) const
	{
		std::cout << x << std::endl;
	}
};

int main()
{
	std::cout << "����" << std::endl;
	{
		boost::variant<int, std::string, double> v;

		// �� ����
		std::cout << v.which() << std::endl;

		v = 1; // int Ÿ���� �� ����
		std::cout << v.which() << std::endl;

		v = 3.14; // double Ÿ���� �� ����
		std::cout << v.which() << std::endl;
	}

	std::cout << "Ÿ�� ����" << std::endl;
	{
		boost::variant<int, std::string, double> v;

		v = 1; // int Ÿ���� �� ����
		if (v.type() == typeid(int)) {
			std::cout << "int" << std::endl;
		}

		v = 3.14; // double Ÿ���� �� ����
		if (v.type() == typeid(double)) {
			std::cout << "double" << std::endl;
		}
	}

	std::cout << "�� ���" << std::endl;
	{
		boost::variant<int, std::string, double> v;
		v = 1;

		// ����
		try {
			int& x = boost::get<int>(v);
			std::cout << x << std::endl;
		}
		catch (boost::bad_get& e) {
			std::cout << e.what() << std::endl;
		}

		// ������
		if (int* x = boost::get<int>(&v)) {
			std::cout << *x << std::endl;
		}
		else {
			std::cout << "int ���� ���� �Ǿ� ���� �ʴ�." << std::endl;
		}
	}

	std::cout << "�� ����" << std::endl;
	{
		boost::variant<boost::blank, int, std::string> v = boost::blank();
		v = 3;

		v = boost::blank();

		if (v.type() == typeid(boost::blank)) {
			std::cout << "blank" << std::endl;
		}
		else {
			std::cout << "no blank" << std::endl;
		}
	}

	std::cout << "���ڿ� �´� �Լ� ȣ���ϱ�" << std::endl;
	{
		// int, string, double
		boost::variant<int, std::string, double> v;

		v = 3; // int
		boost::apply_visitor(var_printer(), v); // visitor���� Ÿ�Կ� �´� ó���� �Ѵ�.

		v = "hello"; // string
		boost::apply_visitor(var_printer(), v);
	}


	return 0;
}