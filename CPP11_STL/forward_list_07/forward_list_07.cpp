
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
	std::cout << "flist1" << std::endl;
	std::forward_list< int > flist1;
	flist1.push_front( 5 );
	flist1.push_front( 7 );
	flist1.push_front( 6 );
    print(flist1); 

	std::cout << "flist2" << std::endl;
	std::forward_list< int > flist2;
    flist2.push_front( 3 );
	flist2.push_front( 2 );
	flist2.push_front( 8 );
	print(flist1); 

	std::cout << "flist1.splice_after(flist1.begin(), flist2 )" << std::endl;
	flist1.splice_after(flist1.begin(), flist2 );
	print(flist1); 
    

	std::cout << "flist3" << std::endl;
	std::forward_list< int > flist3;
	flist3.push_front( 15 );
	flist3.push_front( 17 );
	flist3.push_front( 16 );
    print(flist3);

	std::cout << "flist4" << std::endl;
	std::forward_list< int > flist4;
    flist4.push_front( 13 );
	flist4.push_front( 12 );
	flist4.push_front( 18 );
	print(flist4);

	std::cout << "flist3.splice_after(flist3.begin(), flist4, flist4.begin() )" << std::endl;
	flist3.splice_after(flist3.begin(), flist4, flist4.begin() );
	print(flist3);

	
	std::cout << "flist5" << std::endl;
	std::forward_list< int > flist5;
	flist5.push_front( 25 );
	flist5.push_front( 27 );
	flist5.push_front( 26 );
    print(flist5);

	std::cout << "flist6" << std::endl;
	std::forward_list< int > flist6;
    flist6.push_front( 23 );
	flist6.push_front( 22 );
	flist6.push_front( 28 );
	print(flist6);

	std::cout << "flist5.splice_after(flist5.begin(), flist6, flist6.begin(), flist6.end() )" << std::endl;
	flist5.splice_after(flist5.begin(), flist6, flist6.begin(), flist6.end() );
	print(flist5);

	return 0;
}

