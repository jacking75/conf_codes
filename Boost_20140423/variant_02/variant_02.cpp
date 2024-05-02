// Boost.Variant로 상속을 대체
// 출처: https://sites.google.com/site/boostjp/tips/variant


#include <iostream>
#include <memory>
#include <vector>
#include <boost/range/adaptor/indirected.hpp>
#include <boost/variant.hpp>


struct Background {
	void update()
	{
		std::cout << "background" << std::endl;
	}
};

struct Character {
	void update()
	{
		std::cout << "character" << std::endl;
	}
};

struct Effect {
	void update()
	{
		std::cout << "effect" << std::endl;
	}
};

struct UpdateVisitor {
	using result_type = void;

	template <class T>
	void operator()(T& x)
	{
		x.update();
	}
};

class TaskList {
	using TaskType = boost::variant<Background, Character, Effect>;
	std::vector<TaskType> taskList_;
public:
	void update()
	{
		for (TaskType& x : taskList_) {
			UpdateVisitor vis;
			boost::apply_visitor(vis, x);
		}
	}

	template <class Task, class... Args>
	void add(Args... args)
	{
		taskList_.push_back(Task(args...));
	}
};

int main()
{
	TaskList task;
	task.add<Background>();
	task.add<Character>();
	task.add<Effect>();

	task.update();

	return 0;
}

/*
struct UpdateInterface {
	virtual void update() = 0;
};

struct Background : public UpdateInterface {
	void update() override
	{
		std::cout << "background" << std::endl;
	}
};

struct Character : public UpdateInterface {
	void update() override
	{
		std::cout << "character" << std::endl;
	}
};

struct Effect : public UpdateInterface {
	void update() override
	{
		std::cout << "effect" << std::endl;
	}
};

class TaskList {
	std::vector<std::unique_ptr<UpdateInterface>> taskList_;
public:
	void update()
	{
		for (UpdateInterface& x : taskList_ | boost::adaptors::indirected) {
			x.update();
		}
	}

	template <class Task, class... Args>
	void add(Args... args)
	{
		taskList_.push_back(std::unique_ptr<UpdateInterface>(new Task(args...)));
	}
};

int main()
{
	TaskList task;
	task.add<Background>();
	task.add<Character>();
	task.add<Effect>();

	task.update();
}
*/