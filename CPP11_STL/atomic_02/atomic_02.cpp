
#include <iostream>
#include <atomic>

int main()
{
	std::atomic<int> Num(0);
	std::cout << Num.load() << std::endl;

	std::atomic_store(&Num, 2);
	std::cout << Num.load() << std::endl;

	int result = std::atomic_load(&Num);
	std::cout << result << std::endl;

	
	std::cout << "암묵적으로 store, load 사용하기" << std::endl;

	int Num2;
	Num = 5;	// store
	Num2 = Num; // laod
	std::cout << Num2 << std::endl;
}

