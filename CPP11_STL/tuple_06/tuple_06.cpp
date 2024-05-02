
#include <tuple>
#include <iostream>
#include <string>


int main()
{
	{
		std::cout << "test 1" << std::endl;

		int n1 = 11, n2 = 9, n3 = 10;
		int n4 = 12, n5 = 10, n6 = 11;
	
		if( std::tie(n1, n2, n3 ) < std::tie(n4, n5, n6) )
		{
			std::cout << "std::tie(n1, n2, n3 ) < std::tie(n4, n5, n6)" << std::endl; 
		}
		else
		{
			std::cout << "std::tie(n1, n2, n3 ) > std::tie(n4, n5, n6)" << std::endl; 
		}
	}

	{
		std::cout << "test 2" << std::endl;

		int n1 = 11, n2 = 9, n3 = 10;
		int n4 = 12, n5 = 10, n6 = 9;
	
		if( std::tie(n1, n2, n3 ) < std::tie(n4, n5, n6) )
		{
			std::cout << "std::tie(n1, n2, n3 ) < std::tie(n4, n5, n6)" << std::endl; 
		}
		else
		{
			std::cout << "std::tie(n1, n2, n3 ) > std::tie(n4, n5, n6)" << std::endl; 
		}
	}

	{
		std::cout << "test 3" << std::endl;

		int n1 = 11, n2 = 9, n3 = 10;
		int n4 = 12, n5 = 8, n6 = 9;
	
		if( std::tie(n1, n2, n3 ) < std::tie(n4, n5, n6) )
		{
			std::cout << "std::tie(n1, n2, n3 ) < std::tie(n4, n5, n6)" << std::endl; 
		}
		else
		{
			std::cout << "std::tie(n1, n2, n3 ) > std::tie(n4, n5, n6)" << std::endl; 
		}
	}

	{
		std::cout << "test 4" << std::endl;

		int n1 = 11, n2 = 9, n3 = 10;
		int n4 = 10, n5 = 8, n6 = 9;
	
		if( std::tie(n1, n2, n3 ) < std::tie(n4, n5, n6) )
		{
			std::cout << "std::tie(n1, n2, n3 ) < std::tie(n4, n5, n6)" << std::endl; 
		}
		else
		{
			std::cout << "std::tie(n1, n2, n3 ) > std::tie(n4, n5, n6)" << std::endl; 
		}
	}

	{
		std::cout << "test 5" << std::endl;

		int n1 = 11, n2 = 1, n3 = 10;
		int n4 = 10, n5 = 10, n6 = 11;
	
		if( std::tie(n1, n2, n3 ) < std::tie(n4, n5, n6) )
		{
			std::cout << "std::tie(n1, n2, n3 ) < std::tie(n4, n5, n6)" << std::endl; 
		}
		else
		{
			std::cout << "std::tie(n1, n2, n3 ) > std::tie(n4, n5, n6)" << std::endl; 
		}
	}
	
	return 0;
}