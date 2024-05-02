
#include <iostream>
#include <forward_list>

struct ITEM
{
	ITEM(int nItemID) { this->nItemID = nItemID; }
	int nItemID;
};

int main()
{
    std::forward_list< int > flist1;
  
    flist1.push_front( 21 );
	flist1.push_front( 23 );
	flist1.push_front( 22 );
              
	flist1.sort();

	for( auto value : flist1 )
    {
		std::cout << value << std::endl;
    }
	std::cout << std::endl;
	
	
	std::forward_list< ITEM > flist2;
  
	flist2.push_front( ITEM(21) );
	flist2.push_front( ITEM(23) );
	flist2.push_front( ITEM(22) );

	flist2.sort( [] (ITEM& item1, ITEM& item2) -> bool { return item1.nItemID > item2.nItemID; } );

	for( auto& item : flist2 )
    {
		std::cout << item.nItemID << std::endl;
    }
	std::cout << std::endl;


	flist2.sort( [] (ITEM& item1, ITEM& item2) -> bool { return item1.nItemID < item2.nItemID; } );

	for( auto& item : flist2 )
    {
		std::cout << item.nItemID << std::endl;
    }

	return 0;
}

