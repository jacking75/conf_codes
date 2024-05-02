
#include <iostream>
#include <atomic>

int main()
{
	std::atomic<int> Num1(10);

	if (std::atomic_exchange(&Num1, 20) == 10) 
	{
		std::cout << "Num1 10에서 " << Num1 << "으로 변경" << std::endl;
	}
	else 
	{
		std::cout << "Num1 변경 실패" << std::endl;
	}


	
	std::atomic<int> Num2(22);

	int expected1 = 22;
	bool result = std::atomic_compare_exchange_strong(&Num2, &expected1, 1);

	if( result )
	{
		std::cout << "Num2와 expected1은 같다. Num2: " << Num2.load() << std::endl;
	}
	else
	{
		std::cout << "Num2와 expected1와 다르다. expected1: " << expected1 << std::endl;
	}

	
	std::atomic<int> Num3(22);
	int expected2 = 21;
	result = std::atomic_compare_exchange_strong(&Num3, &expected2, 1);

	if( result )
	{
		std::cout << "Num2와 expected2은 같다. Num3: " << Num3 << std::endl;
	}
	else
	{
		std::cout << "Num2와 expected2와 다르다. expected2: " << expected2 << std::endl;
	}
	
	return 0;
}


