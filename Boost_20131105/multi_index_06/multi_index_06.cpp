#include <iostream>
#include <string>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/key_extractors.hpp>
#include <boost/multi_index/sequenced_index.hpp>

// boost::multi_index::identity�� ���� �������� ����� �� ���ĸ� ���� ���� ���


class CHARACTER 
{
public:
	CHARACTER( const int nLevel, const char* pszName ) : m_nLevel(nLevel), m_Name(pszName)
	{
	}

	const int Level() const { return m_nLevel; }
	const std::string Name() const { return m_Name; }

	bool operator < (const CHARACTER& Char) const {
		return m_nLevel < Char.Level();
	}

private:
	int m_nLevel;
	std::string m_Name;
};

// �����̳��� Ű�� ����
typedef boost::multi_index::sequenced<> Index_Sequenced;
typedef boost::multi_index::identity<CHARACTER> Index_Char;
typedef boost::multi_index::const_mem_fun< CHARACTER, const std::string, &CHARACTER::Name > Index_Ordered_Name;

// �ε��� Ÿ���� ����
typedef struct indices : public boost::multi_index::indexed_by
	<
		Index_Sequenced 
		, boost::multi_index::ordered_non_unique<Index_Char>
		, boost::multi_index::ordered_unique<Index_Ordered_Name>
	>
{
	enum INDEX
	{
		IDX_SEQUENCE = 0				
		, IDX_NON_UNIQUE_CHAR
		, IDX_UNIQUE_NAME
		, IDX_END		
	};
} INDICES;

typedef boost::multi_index_container<CHARACTER, indices> Container;


int main() 
{
	Container CharacterSet;

	CharacterSet.push_back( CHARACTER(2, "test1"));
	CharacterSet.push_back( CHARACTER(3, "test2"));
	CharacterSet.push_back( CHARACTER(1, "test3"));
	

	std::cout << "�Է� ������� ĳ���� ���" << std::endl;
	std::for_each( CharacterSet.begin(), CharacterSet.end(), [](const CHARACTER& Char) { 
						std::cout << "Level : " << Char.Level() << ", Name : " << Char.Name() << std::endl;
					} );
	std::cout << std::endl << std::endl;


	std::cout << "������ ���ĵ� ĳ���� ���" << std::endl;
	Container::nth_index<indices::IDX_NON_UNIQUE_CHAR>::type& Index1 = CharacterSet.get<indices::IDX_NON_UNIQUE_CHAR>();
	std::for_each( Index1.begin(), Index1.end(), [](const CHARACTER& Char) { 
				std::cout << "Level : " << Char.Level() << ", Name : " << Char.Name() << std::endl;
					} );
	std::cout << std::endl;

	


	return 0;
}
