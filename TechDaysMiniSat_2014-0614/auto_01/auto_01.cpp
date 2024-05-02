#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>


// 戻り値型の後方宣言が必要なく
// auto のみで定義
template<typename T, typename U>
auto
plus(T t, U u){
	return t + u;
}

template<typename Seq>
auto
slice1_4(Seq&& seq){
	return seq | boost::adaptors::sliced(1, 4);
}


// 型さえ合っていれば複数の return 文を定義してもよい
auto 
is_even(int n){
	if (n % 2 == 0){
		return true;
	}
	else{
		return false;
	}
}

// なのでこういう書き方はコンパイルエラー
// auto
// is_odd(int n){
//     if( n % 2 != 0 ){
//         return 1;
//     }
//     else{
//         return false;
//     }
// }

int
main(){
	std::cout << plus(1, 3.14f) << std::endl;
	std::cout << plus(3.14f, 1) << std::endl;

	auto v = std::initializer_list<int>{1, 2, 3, 4, 5};
	auto result = slice1_4(v);
	for (auto&& n : result){
		std::cout << n << std::endl;
	}

	std::cout << is_even(2) << std::endl;
	std::cout << is_even(9) << std::endl;

	return 0;
}