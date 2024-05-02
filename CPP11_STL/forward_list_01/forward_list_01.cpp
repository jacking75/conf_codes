
#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list< int > flist;
  
    // 추가하기
    for( int i = 0; i < 5; ++i )
    {
		flist.push_front( i );
    }

	std::cout << "flist의 첫번 째 위치 값: " << flist.front() << std::endl;
                    
    // 순회
    for( auto value : flist )
    {
        std::cout << value;
    }
    std::cout << std::endl; 
    

	std::forward_list< int > flist2;
	flist2.assign(3, 11);

	for( auto value : flist2 )
    {
        std::cout << value;
    }
    std::cout << std::endl;


	std::forward_list< int > flist3;
	flist3.assign(flist.begin(), flist.end());

	for( auto value : flist3 )
    {
        std::cout << value;
    }
    std::cout << std::endl;

	return 0;
}




