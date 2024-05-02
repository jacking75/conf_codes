// 출처: https://sites.google.com/site/boostjp/tips/variant

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
	std::cout << "저장" << std::endl;
	{
		boost::variant<int, std::string, double> v;

		// 빈 상태
		std::cout << v.which() << std::endl;

		v = 1; // int 타입의 값 저장
		std::cout << v.which() << std::endl;

		v = 3.14; // double 타입의 값 저장
		std::cout << v.which() << std::endl;
	}

	std::cout << "타입 판정" << std::endl;
	{
		boost::variant<int, std::string, double> v;

		v = 1; // int 타입의 값 저장
		if (v.type() == typeid(int)) {
			std::cout << "int" << std::endl;
		}

		v = 3.14; // double 타입의 값 저장
		if (v.type() == typeid(double)) {
			std::cout << "double" << std::endl;
		}
	}

	std::cout << "값 얻기" << std::endl;
	{
		boost::variant<int, std::string, double> v;
		v = 1;

		// 참조
		try {
			int& x = boost::get<int>(v);
			std::cout << x << std::endl;
		}
		catch (boost::bad_get& e) {
			std::cout << e.what() << std::endl;
		}

		// 포인터
		if (int* x = boost::get<int>(&v)) {
			std::cout << *x << std::endl;
		}
		else {
			std::cout << "int 값은 저장 되어 있지 않다." << std::endl;
		}
	}

	std::cout << "값 비우기" << std::endl;
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

	std::cout << "인자에 맞는 함수 호출하기" << std::endl;
	{
		// int, string, double
		boost::variant<int, std::string, double> v;

		v = 3; // int
		boost::apply_visitor(var_printer(), v); // visitor으로 타입에 맞는 처리를 한다.

		v = "hello"; // string
		boost::apply_visitor(var_printer(), v);
	}


	return 0;
}