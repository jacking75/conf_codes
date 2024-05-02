
#include <iostream>
#include <unordered_map>

// 게임 캐릭터
struct GameCharacter
{
	GameCharacter() { }
	GameCharacter( int CharCd, int Level, int Money )
	{
		_CharCd = CharCd;
		_Level = Level;
		_Money = Money;
	}
	int _CharCd; // 캐릭터코드
	int _Level; // 레벨
	int _Money; // 돈
};

int main()
{
	std::unordered_map<int, GameCharacter> Characters;
	
	GameCharacter Character1(12, 7, 1000 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(12, Character1));
	GameCharacter Character2(15, 20, 111000 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(15, Character2));
	GameCharacter Character3(7, 34, 3345000 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(7, Character3));
	GameCharacter Character4(14, 12, 112200 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(14, Character4));
	GameCharacter Character5(25, 3, 5000 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(25, Character5));
	
	
	std::cout << "저장한 캐릭터 리스트" << std::endl;
	for( auto& Char : Characters )
	{
		std::cout << "캐릭터 코드 : " << Char.second._CharCd; 
		std::cout << " | 레벨 : " << Char.second._Level;
		std::cout << " | 가진 돈 : " << Char.second._Money << std::endl;
	}
	std::cout << std::endl;
	
	
	std::cout << "lower_bound(14)" << std::endl;
	auto Iter = Characters.lower_bound(14);
	while( Iter != Characters.end() )
	{
		std::cout << "캐릭터 코드 : " << Iter->second._CharCd; 
		std::cout << " | 레벨 : " << Iter->second._Level;
		std::cout << " | 가진 돈 : " << Iter->second._Money << std::endl;
		++Iter;
	}
	std::cout << std::endl;
	

	std::cout << "upper_bound(7)" << std::endl;
	Iter = Characters.upper_bound(7);
	while( Iter != Characters.end() )
	{
		std::cout << "캐릭터 코드 : " << Iter->second._CharCd; 
		std::cout << " | 레벨 : " << Iter->second._Level;
		std::cout << " | 가진 돈 : " << Iter->second._Money << std::endl;
		++Iter;
	}

	return 0;
}



