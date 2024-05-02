#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
 
int main()
{
    std::cout << "range base for - vector" << std::endl;
 
    std::vector<int> NumberList;
    NumberList.push_back( 1 );
    NumberList.push_back( 2 );
    NumberList.push_back( 3 );
          
    for( auto i : NumberList )
    {
                std::cout << i << std::endl;
    }
    std::cout << std::endl;
 
 
 
    std::cout << "range base for - unordered_map" << std::endl;
 
    std::unordered_map<int, std::string> NumString;
    NumString.insert( std::make_pair<int, std::string>(1, "1") );
    NumString.insert( std::make_pair<int, std::string>(2, "2") );
    NumString.insert( std::make_pair<int, std::string>(3, "3") );
 
    for( auto i : NumString )
    {
                std::cout << "key : " << i.first << ", value : " << i.second << std::endl;
    }
 
    std::cout << std::endl;
 
    return 0;
}
