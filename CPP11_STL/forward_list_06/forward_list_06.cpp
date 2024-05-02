
#include <iostream>
#include <forward_list>

void print(std::forward_list< int >& flist)
{
	for( auto value : flist )
    {
		std::cout << value << std::endl;
    }

	std::cout << std::endl;
}

struct ITEM
{
	ITEM(int nItemID) { this->nItemID = nItemID; }
	int nItemID;
};

void print(std::forward_list< ITEM >& flist)
{
	for( auto& item : flist )
    {
		std::cout << "¾ÆÀÌÅÛ ID: " << item.nItemID << std::endl;
    }

	std::cout << std::endl;
}


int main()
{
    std::forward_list< int > flist1;
	flist1.push_front( 5 );
	flist1.push_front( 7 );
	flist1.push_front( 6 );
    
	print(flist1);


	std::forward_list< int > flist2;
  
    flist2.push_front( 3 );
	flist2.push_front( 2 );
	flist2.push_front( 8 );

	print(flist2);

    std::cout << "merge" << std::endl;

	flist1.merge(flist2);
	print(flist1); 
    


	std::forward_list< ITEM > flist3;
  
	flist3.push_front( ITEM(5) );
	flist3.push_front( ITEM(7) );
	flist3.push_front( ITEM(6) );

	print(flist3);


	std::forward_list< ITEM > flist4;
  
	flist4.push_front( ITEM(3) );
	flist4.push_front( ITEM(2) );
	flist4.push_front( ITEM(8) );

	print(flist4);

	std::cout << "merge" << std::endl;

	flist3.merge(flist4, [] (ITEM& item1, ITEM& item2) -> bool 
						{ return item1.nItemID > item2.nItemID; }
					);
	print(flist3);

	return 0;
}

