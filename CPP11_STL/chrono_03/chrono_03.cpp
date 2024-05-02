
#include <chrono>
#include <iostream>

int main()
{
	{
		std::chrono::hours H1(1); // 1½Ã°£
		
		std::cout << "H1(1) : " << H1.count() << std::endl;
		

		std::chrono::seconds S1(10);
		std::chrono::seconds S2(120);

		std::cout << "S1(10) : " << S1.count() << std::endl;
		std::cout << "S2(120) : " << S2.count() << std::endl;
	}

	{
		std::chrono::hours H1(1); 
		std::chrono::hours H2(2); 
		std::chrono::hours H3 = H1 + H2;

		std::cout << "H1 + H2 = : " << H3.count() << std::endl;


		std::chrono::seconds S1(10);
		std::chrono::milliseconds MILS1(100);
		std::chrono::milliseconds MILS2 = S1 + MILS1;

		std::cout << "S1 + MILS1 = : " << MILS2.count() << std::endl;


		std::chrono::seconds S2 = std::chrono::duration_cast< std::chrono::seconds >(S1 + MILS1);

		std::cout << "S1 + MILS1 = : " << S2.count() << std::endl;
	}

	return 0;
}

