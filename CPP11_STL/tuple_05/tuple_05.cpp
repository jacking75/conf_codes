
#include <tuple>
#include <iostream>
#include <string>

int main()
{
	std::tuple<int, std::string> UserInfo(1002, "jacking");
	std::tuple<int, int> GameResult(12, 3);
	
	auto UserGaemResult = std::tuple_cat(UserInfo, GameResult);
	
	std::cout << std::get<0>(UserGaemResult) << std::endl;
	std::cout << std::get<1>(UserGaemResult) << std::endl;
	std::cout << std::get<2>(UserGaemResult) << std::endl;
	std::cout << std::get<3>(UserGaemResult) << std::endl;
	
	return 0;
}


