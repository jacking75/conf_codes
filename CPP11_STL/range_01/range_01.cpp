#include <iostream>
  
int main()
{
    int NumberList[5] = { 1, 2, 3, 4, 5 };
 
          
    std::cout << "일반적인 for 문" << std::endl;
          
    for( int i = 0; i < 5; ++i )
    {
                std::cout << i << std::endl;
    }
 
 
    std::cout << "VC++ 특화의 for each문" << std::endl;
 
    for each( int i in NumberList )
    {
                std::cout << i << std::endl;
    }
 
 
    std::cout << "range base for 문" << std::endl;
 
    for( auto i : NumberList )
    {
                std::cout << i << std::endl;
    }
 
    return 0;
}

