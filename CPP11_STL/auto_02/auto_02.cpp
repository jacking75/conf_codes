#include <iostream>


int main()
{
	int UserMode = 4;
	auto* pUserMode = &UserMode;
	std::cout << "pUserMode : Value - " << *pUserMode << ", address : " << pUserMode << std::endl;

	auto& refUserMode = UserMode;
	refUserMode = 5;
 	std::cout << "UserMode : Value - " << UserMode << " | refUserMode : Value - " << refUserMode << std::endl;
		
	return 0;
}
