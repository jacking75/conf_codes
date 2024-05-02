#include <iostream>
#include <unordered_map>

// 게임 캐릭터
struct GameCharacter
{
	// 아래의 인자를 가지는 생성자를 정의한 경우는
	// 꼭 기본 생성자를 정의해야 컨테이너에서 사용할 수 있다.
	GameCharacter() { }
	GameCharacter( int CharCd, int Level, int Money )
	{
		_CharCd = CharCd;
		_Level = Level;
		_Money = Money;
	}

	int _CharCd; // 캐릭터 코드
	int _Level; // 레벨
	int _Money; // 돈
};

int main()
{
	std::unordered_map<int, GameCharacter> Characters;
	
	GameCharacter Character1(12, 7, 1000 );
	Characters.insert( std::pair<int, GameCharacter>(12, Character1) );

	GameCharacter Character2(14, 8, 1001 );
	Characters[14] = Character2;

	GameCharacter Character3(15, 8, 1002 );
	Characters[15] = Character3;
	
	for( auto& Iter1 : Characters )
	{
		std::cout << "캐릭터 코드 : " << Iter1.second._CharCd;
		std::cout << " | 레벨 : " << Iter1.second._Level;
		std::cout << "| 가진 돈 : " << Iter1.second._Money << std::endl;
	}


	// [] 업데이트와 검색
	Characters[12]._Level = 17;
	std::cout << "[] 캐릭터 12 레벨 : " << Characters[12]._Level << std::endl;

	// at 업데이트와 검색
	Characters.at(15)._Level = 9;
	std::cout << "at 캐릭터 15 레벨 : " << Characters.at(15)._Level << std::endl;


	for( auto& Iter1 : Characters )
	{
		std::cout << "캐릭터 코드 : " << Iter1.second._CharCd;
		std::cout << " | 레벨 : " << Iter1.second._Level;
		std::cout << "| 가진 돈 : " << Iter1.second._Money << std::endl;
	}

	
	// [] 검색 - 없는 것 16
	std::cout << "[] 캐릭터 16 레벨 : " << Characters[16]._Level << std::endl;

	for( auto& Iter1 : Characters )
	{
		std::cout << "캐릭터 코드 : " << Iter1.second._CharCd;
		std::cout << " | 레벨 : " << Iter1.second._Level;
		std::cout << "| 가진 돈 : " << Iter1.second._Money << std::endl;
	}

	return 0;
}