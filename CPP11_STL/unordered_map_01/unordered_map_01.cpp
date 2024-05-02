
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
	
	// 추가
	GameCharacter Character1(12, 7, 1000 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(12, Character1));
	GameCharacter Character2(15, 20, 111000 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(15, Character2));
	GameCharacter Character3(200, 34, 3345000 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(200, Character3));
	
	// iterator와 begin, end 사용
	// 저장한 요소를 정방향으로 순회
	for( auto Iter1 = Characters.begin(); Iter1 != Characters.end(); ++Iter1 )
	{
		std::cout << "캐릭터 코드 : " << Iter1->second._CharCd;
		std::cout << " | 레벨 : " << Iter1->second._Level;
		std::cout << "| 가진 돈 : " << Iter1->second._Money << std::endl;
	}
	std::cout << std::endl;

	
	// rbegin, rend 사용
	// 저장한 요소의 역방향으로순회
	for( auto RIter = Characters.rbegin(); RIter != Characters.rend(); ++RIter )
	{
		std::cout << "캐릭터 코드 : " << RIter->second._CharCd;
		std::cout << " | 레벨 : " << RIter->second._Level;
		std::cout << "| 가진 돈 : " << RIter->second._Money << std::endl;
	}
	std::cout << std::endl << std::endl;
	
	
	// Characters에 저장한 요소 수
	int CharacterCount = Characters.size();
	
	// 검색.
	// 캐릭터 코드 15인 캐릭터를 찾는다.
	auto FindIter = Characters.find(15);
	
	// 찾지 못했다면 FindIter은 end 위치의 반복자가 리턴된다.
	if( Characters.end() == FindIter )
	{
		std::cout << "캐릭터 코드가 20인 캐릭터가 없습니다" << std::endl;
	}
	else
	{
		std::cout << "캐릭터 코드가 15인 캐릭터를 찾았습니다." << std::endl;
		std::cout << "캐릭터 코드 : " << FindIter->second._CharCd;
		std::cout <<  " | 레벨 : " << FindIter->second._Level;
		std::cout << "| 가진 돈 : " << FindIter->second._Money << std::endl;
	}
	std::cout << std::endl;


	for( auto Iter1 = Characters.begin(); Iter1 != Characters.end(); ++Iter1 )
	{
		std::cout << "캐릭터 코드 : " << Iter1->second._CharCd; 
		std::cout << " | 레벨 : " << Iter1->second._Level;
		std::cout << "| 가진 돈 : " << Iter1->second._Money << std::endl;
	}
	std::cout << std::endl << std::endl;
	
	
	// 삭제
	// 캐릭터 코드가 15인 캐릭터를 삭제한다.
	Characters.erase( 15 );
	
	for( auto Iter1 = Characters.begin(); Iter1 != Characters.end(); ++Iter1 )
	{
		std::cout << "캐릭터 코드 : " << Iter1->second._CharCd;
		std::cout << " | 레벨 : " << Iter1->second._Level;
		std::cout << "| 가진 돈 : " << Iter1->second._Money << std::endl;
	}
	std::cout << std::endl << std::endl;
	
	
	// 모든 캐릭터를 삭제한다.
	Characters.erase( Characters.begin(), Characters.end() );
	
	// Characters 공백 조사
	if( Characters.empty() )
	{
		std::cout << "Characters는 비어 있습니다." << std::endl;
	}

	return 0;
}

