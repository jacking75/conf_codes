//출처: http://faithandbrave.hateblo.jp/entry/20120703/1341298054

#include <iostream>
#include <vector>
#include <string>
#include <boost/scope_exit.hpp>
#include <boost/bind.hpp>
#include <boost/range/algorithm/for_each.hpp>

struct person {
	int id;
	std::string name;

	person(int id, const std::string& name)
		: id(id), name(name) {}

	void print()
	{
		std::cout << name << std::endl;
	}
};

class world {
	std::vector<person> persons_;
public:
	void add_person(const person& p)
	{
		bool commit = false;

		BOOST_SCOPE_EXIT(&commit, this_) {
			if (!commit)
				this_->persons_.pop_back(); // this_로 private 멤버에 접근
		} BOOST_SCOPE_EXIT_END

			persons_.push_back(p);

		if (p.id > 0)
			commit = true;
	}

	void print()
	{
		boost::for_each(persons_, boost::bind(&person::print, _1));
	}
};

int main()
{
	world w;
	w.add_person(person(10, "Alice"));
	w.add_person(person(-1, "Bob"));

	w.print();
}