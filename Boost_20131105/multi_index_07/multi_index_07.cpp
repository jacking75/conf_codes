#include <iostream>
#include <string>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/key_extractors.hpp>
#include <boost/tuple/tuple.hpp>

// replacce ���

class CHARACTER 
{
public:
	CHARACTER( const int nID, const int nLevel, const int nExp ) : m_nID(nID), m_nLevel(nLevel), m_nExp(nExp)
	{
	}

	const int Level() const { return m_nLevel; }
	const int Exp() const { return m_nExp; }

	int m_nLevel;
	int m_nExp;
	int m_nID;
};

// �����̳��� Ű�� ����
typedef boost::multi_index::const_mem_fun<CHARACTER, const int, &CHARACTER::Level> IDX_LEVEL;
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
	CharacterSet.insert( CHARACTER(4, 3, 444));
	CharacterSet.insert( CHARACTER(5, 1, 11));
	CharacterSet.insert( CHARACTER(6, 1, 12));
	CharacterSet.insert( CHARACTER(7, 1, 10));
	CharacterSet.insert( CHARACTER(8, 4, 41));
	

	std::cout << "��� ĳ���� ���" << std::endl;
	std::for_each( CharacterSet.begin(), CharacterSet.end(), [](const CHARACTER& Char) { 
		std::cout << "CharID : " << Char.m_nID << ", Level : " << Char.m_nLevel << std::endl;
					} );
	std::cout << std::endl;


	
	/// replace
	std::cout << "ĳ���� ID 3�� ����" << std::endl;

	Container::nth_index<indices::IDX_UNIQUE_CHARID>::type& Index1 = CharacterSet.get<indices::IDX_UNIQUE_CHARID>();
	Container::nth_index_iterator<indices::IDX_UNIQUE_CHARID>::type iter = Index1.find(3);

	if (Index1.end() != iter) 
	{
		std::cout << "CharID : " << (*iter).m_nID << "�� CharID:33, Level:33, Exp:333�� ����" << std::endl;

		CHARACTER Char( 33, 333, 3333 );
		Index1.replace( iter, Char );
	}
	std::cout << std::endl;

	std::cout << "��� ĳ���� ���" << std::endl;
	std::for_each( CharacterSet.begin(), CharacterSet.end(), [](const CHARACTER& Char) { 
		std::cout << "CharID : " << Char.m_nID << ", Level : " << Char.m_nLevel << std::endl;
					} );
	std::cout << std::endl;

	std::cout << "ĳ���� ID 33�� �˻�" << std::endl;
	Container::nth_index<indices::IDX_UNIQUE_CHARID>::type& Index2 = CharacterSet.get<indices::IDX_UNIQUE_CHARID>();
	iter = Index2.find(33);

	if (Index2.end() != iter) 
	{
		std::cout << "���� - CharID : " << (*iter).m_nID << ", Level : " << (*iter).m_nLevel << std::endl;
	}
	else
	{
		std::cout << "CharID 33�� �˻� ����" << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
	

	/// replace - fail
	Container::nth_index<indices::IDX_UNIQUE_CHARID>::type& Index3 = CharacterSet.get<indices::IDX_UNIQUE_CHARID>();
	iter = Index3.find(4);

	if (Index3.end() != iter) 
	{
		std::cout << "CharID : " << (*iter).m_nID << "�� 44�� ����" << std::endl;

		CHARACTER& Char = (CHARACTER&)(*iter);
		Char.m_nID = 44;
		Index1.replace( iter, Char );
	}
	std::cout << std::endl;

	std::for_each( CharacterSet.begin(), CharacterSet.end(), [](const CHARACTER& Char) { 
		std::cout << "CharID : " << Char.m_nID << ", Level : " << Char.m_nLevel << std::endl;
					} );
	std::cout << std::endl;

	Container::nth_index<indices::IDX_UNIQUE_CHARID>::type& Index4 = CharacterSet.get<indices::IDX_UNIQUE_CHARID>();
	iter = Index4.find(44);

	if (Index4.end() != iter) 
	{
		std::cout << "���� - CharID : " << (*iter).m_nID << ", Level : " << (*iter).m_nLevel << std::endl;
	}
	else
	{
		std::cout << "CharID 44�� �˻� ����" << std::endl;
	}
	
	return 0;
}
