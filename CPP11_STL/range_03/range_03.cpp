#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> NumberList;
    NumberList.push_back( 1 );
    NumberList.push_back( 2 );
    NumberList.push_back( 3 );
          
    for( auto i : NumberList )
    {
                std::cout << i << " * 10 : ";
 
                i *= 10;
                std::cout << i << std::endl;
    }
 
    for( auto i : NumberList )
    {
                std::cout << i << "  ";
    }
          
    std::cout << std::endl << std::endl;
 
 
    for( auto &i : NumberList )
    {
                std::cout << i << " * 10 : ";
 
                i *= 10;
                std::cout << i << std::endl;
    }
 
    for( auto i : NumberList )
    {
                std::cout << i << "  ";
    }
 
    std::cout << std::endl;
 
    return 0;
}
