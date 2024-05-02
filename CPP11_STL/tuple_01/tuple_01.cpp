
#include <tuple>
#include <iostream>
#include <string>

struct ITEM
{
	int nID;
};

int main()
{
	ITEM item;
	item.nID = 10001;

	std::tuple<int, std::string, ITEM> UserItem = std::tuple<int, std::string, ITEM>(1, "jacking", item);

	std::cout << std::get<0>(UserItem) << std::endl;
	std::cout << std::get<1>(UserItem) << std::endl;
	std::cout << std::get<2>(UserItem).nID << std::endl;


	std::get<0>(UserItem)		= 2;
	std::get<1>(UserItem)		= "jacking75";
	std::get<2>(UserItem).nID	= 10002;

	std::cout << std::get<0>(UserItem) << std::endl;
	std::cout << std::get<1>(UserItem) << std::endl;
	std::cout << std::get<2>(UserItem).nID << std::endl;

	return 0;
}


