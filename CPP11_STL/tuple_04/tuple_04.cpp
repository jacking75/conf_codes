
#include <tuple>
#include <iostream>
#include <string>

int main()
{
	std::cout << "- 참조 데이터를 저장하는 tuple 만들기" << std::endl;
	{
		int nUserIndex = 11;
		std::string UserName = "jacking";
	
		auto refUserItem = std::tie(nUserIndex, UserName);
	
		std::cout << std::get<0>(refUserItem) << std::endl;
		std::cout << std::get<1>(refUserItem) << std::endl;

		std::get<0>(refUserItem) = 12;
		std::get<1>(refUserItem) = "jacking75";

		std::cout << nUserIndex << std::endl;
		std::cout << UserName << std::endl;
	}

	std::cout << "- tuple에 저장된 데이터를 일괄적으로 변수에 담기" << std::endl;
	{
		std::tuple<int, std::string> UserInfo(1002, "jacking");

		int nUserIndex = 0;
		std::string UserName;

		std::tie(nUserIndex, UserName) = UserInfo;

		std::cout << nUserIndex << std::endl;
		std::cout << UserName << std::endl;
	}

	std::cout << "- 일부 요소를 무시하고 일괄적으로 변수에 담기" << std::endl;
	{
		std::tuple<int, std::string, int> UserInfo(1003, "jacking", 22);

		int nUserIndex = 0;
		int nLevel = 0;

		std::tie(nUserIndex, std::ignore, nLevel) = UserInfo;

		std::cout << nUserIndex << std::endl;
		std::cout << nLevel << std::endl;
	}

	return 0;
}



