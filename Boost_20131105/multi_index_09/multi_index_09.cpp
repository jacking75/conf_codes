#include <iostream>
#include <string>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/key_extractors.hpp>
#include <boost/tuple/tuple.hpp>

// http://d.hatena.ne.jp/faith_and_brave/20110510/1305001676
// VC++ 6.0 or VC++ 7.0���� Ŭ������ ��������� key�� ������� ���� �� ���

class CHARACTER 
{
public:
	CHARACTER( const int nID, const int nLevel, const int nExp ) : m_nID(nID), m_nLevel(nLevel), m_nExp(nExp)
	{
	}

	const int Level() const { return m_nLevel; }
	const int Exp() const { return m_nExp; }

	int m_nID;
	int m_nLevel;
	int m_nExp;
};

// �����̳��� Ű�� ����
typedef boost::multi_index::member_offset<CHARACTER, int, offsetof(CHARACTER, m_nLevel)> IDX_LEVEL;
typedef boost::multi_index::member<CHARACTER, int, &CHARACTER::m_nID> IDX_CHARID;

// �ε��� Ÿ���� ����
typedef struct indices : public boost::multi_index::indexed_by
	<
		boost::multi_index::hashed_unique<IDX_CHARID>
		, boost::multi_index::hashed_non_unique<IDX_LEVEL>
	>
{
	enum INDEX
	{
		IDX_UNIQUE_CHARID
		, IDX_NON_UNIQUE_LEVEL 
		, IDX_END		
	};
} INDICES;

typedef boost::multi_index_container<CHARACTER, indices> Container;


int main() 
{
	Container CharacterSet;

	CharacterSet.insert( CHARACTER(1, 2, 21));
	CharacterSet.insert( CHARACTER(2, 3, 31));
	CharacterSet.insert( CHARACTER(3, 23, 39));
	CharacterSet.insert( CHARACTER(4, 3, 35));
	CharacterSet.insert( CHARACTER(5, 1, 11));
	CharacterSet.insert( CHARACTER(6, 1, 12));
	CharacterSet.insert( CHARACTER(7, 1, 10));
	CharacterSet.insert( CHARACTER(8, 4, 41));
	

	std::for_each( CharacterSet.begin(), CharacterSet.end(), [](const CHARACTER& Char) { 
		std::cout << "CharID : " << Char.m_nID << ", Level : " << Char.m_nLevel << std::endl;
					} );
	std::cout << std::endl;


	return 0;
}