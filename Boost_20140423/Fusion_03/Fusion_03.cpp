// √‚√≥: https://sites.google.com/site/boostjp/tips/tuple

#include <iostream>
#include <string>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/for_each.hpp>

namespace fusion = boost::fusion;

struct Person {
	int id;
	std::string name;
	int age;

	Person(int id, const std::string& name, int age)
		: id(id), name(name), age(age) {}
};

BOOST_FUSION_ADAPT_STRUCT
(
	Person,
	(int, id)
	(std::string, name)
	(int, age)
	)

struct disper {
	template <class T>
	void operator()(const T& x) const
	{
		std::cout << x << std::endl;
	}
};

int main()
{
	const Person person(3, "Alice", 18);

	fusion::for_each(person, disper());

	return 0;
}



