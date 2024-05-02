
#include <array>
#include <iostream>

int main()
{
	std::array<int, 5> arr1;
	
	for( int i = 0; i < 5; ++i )
	{
		arr1[i] = i+1;
	}

	for( int i = 0; i < 5; ++i )
	{
		std::cout << arr1[i] << std::endl;
	}



	std::array<int, 5> arr2 = { 11, 12, 13, 14, 15 };

	for( auto iter = arr2.begin(); iter != arr2.end(); ++iter )
	{
		std::cout << *iter << std::endl;
	}

	return 0;
}


