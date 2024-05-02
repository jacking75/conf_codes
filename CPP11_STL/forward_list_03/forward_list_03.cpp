
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

int main()
{
    std::forward_list< int > flist;
  
    // 추가하기
    for( int i = 0; i < 6; ++i )
    {
		flist.push_front( i );
    }          
	print(flist);


    std::cout << "pop_front로 삭제" << std::endl;

	flist.pop_front();
	print(flist); 
    

	std::cout << "erase_after로 삭제" << std::endl;

	flist.erase_after( flist.begin() );
	print(flist); 

	flist.erase_after( flist.begin(), flist.end() );
	print(flist);

	return 0;
}


