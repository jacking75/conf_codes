
#include <iostream>
#include <string>
#include <unordered_map>

void PrintAll(std::unordered_map<std::string, int>& CharInfo)
{
	std::cout << "저장된 캐릭터 리스트" << std::endl;

	for( auto& info : CharInfo )
	{
		std::cout << "캐릭터 이름 : " << info.first;
		std::cout << "| 가진 돈 : " << info.second << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	std::unordered_map<std::string, int> CharacterMoneys;
	
	// 추가
	CharacterMoneys.insert(std::pair<std::string, int>("test1", 1100));
	CharacterMoneys.insert(std::pair<std::string, int>("test2", 2100));
	CharacterMoneys.insert(std::pair<std::string, int>("test3", 3100));
	
	PrintAll(CharacterMoneys);

	
	auto Iter1 = CharacterMoneys.emplace_hint(CharacterMoneys.begin(), "test2", 4000);
	
	std::cout << "캐릭터 이름 : " << Iter1->first;
	std::cout << "| 가진 돈 : " << Iter1->second << std::endl;

	PrintAll(CharacterMoneys);


	auto Iter2 = CharacterMoneys.emplace_hint(CharacterMoneys.begin(), "test4", 4000);
	
	std::cout << "캐릭터 이름 : " << Iter2->first;
	std::cout << "| 가진 돈 : " << Iter2->second << std::endl;

	PrintAll(CharacterMoneys);

	return 0;
}

