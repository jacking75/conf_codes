
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

	std::tuple<int, std::string, ITEM> UserItem = std::make_tuple(1, "jacking", item);

	std::cout << std::get<0>(UserItem) << std::endl;
	std::cout << std::get<1>(UserItem) << std::endl;
	std::cout << std::get<2>(UserItem).nID << std::endl;
	
	return 0;
}


