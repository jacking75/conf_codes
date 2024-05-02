
#include <iostream>
#include <bitset>
#include <atomic>

int main()
{
	std::atomic<int> Num1(10);

	int before = std::atomic_fetch_add(&Num1, 7);
	std::cout << "연산 전: " << before << ", 연산 후:" << Num1 << std::endl;
	
	before = std::atomic_fetch_sub(&Num1, 2);
	std::cout << "연산 전: " << before << ", 연산 후:" << Num1 << std::endl;
	std::cout << std::endl;


	int a = 0x0b;
	int b = 0x0e;
	
	std::atomic<int> Num2(a);

	std::atomic_fetch_and(&Num2, b);
	std::cout << "       a:" << std::bitset<4>(a).to_string() << std::endl;
	std::cout << "       b:" << std::bitset<4>(b).to_string() << std::endl;
	std::cout << "and 연산:" << std::bitset<4>(Num2).to_string() << std::endl;
	std::cout << std::endl;


	std::atomic<int> Num3(a);
	std::atomic_fetch_or(&Num3, b);

	std::cout << "      a:" << std::bitset<4>(a).to_string() << std::endl;
	std::cout << "      b:" << std::bitset<4>(b).to_string() << std::endl;
	std::cout << "or 연산:" << std::bitset<4>(Num3).to_string() << std::endl;
	std::cout << std::endl;


	std::atomic<int> Num4(a);
	std::atomic_fetch_xor(&Num4, b);

	std::cout << "       a:" << std::bitset<4>(a).to_string() << std::endl;
	std::cout << "       b:" << std::bitset<4>(b).to_string() << std::endl;
	std::cout << "xor 연산:" << std::bitset<4>(Num4).to_string() << std::endl;

	return 0;
}



