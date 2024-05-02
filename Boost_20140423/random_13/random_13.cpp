//출처: http://faithandbrave.hateblo.jp/entry/20130410/1365583499

#include <iostream>
#include <boost/random.hpp>

class logged_generator {
	std::size_t& generate_count_;
	boost::random::mt19937& gen_;
public:
	typedef boost::random::mt19937 engine_type;
	typedef engine_type::result_type result_type;

	logged_generator(std::size_t& c, engine_type& gen)
		: generate_count_(c), gen_(gen) {}

	static result_type min() { return engine_type::min(); }
	static result_type max() { return engine_type::max(); }

	result_type operator()()
	{
		const result_type result = gen_();
		++generate_count_; // 생성 횟수를 카운트한다		
		return result;
	}
};

template <class Generator, class Distribution>
void generate(Generator& gen, Distribution& dist)
{
	for (int i = 0; i < 3; ++i) {
		std::cout << dist(gen) << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::size_t seed = 3;
	std::size_t generate_count = 0; // 난수를 생성한 횟수

	boost::random::mt19937 mt_gen(seed);

	logged_generator gen{ generate_count, mt_gen };
	boost::random::uniform_int_distribution<> dist{ 0, 10 };

	generate(gen, dist);

	// seed와 난수 생성 횟수를 설정하고, 제네레이터 상태를 복구한다.
	boost::random::mt19937 restored_mt_gen{ seed };
	restored_mt_gen.discard(generate_count);


	// 앞에서 사용한 제네레이터 오브젝트와 결과를 비교해 본다
	generate(restored_mt_gen, dist);
	generate(gen, dist);

	return 0;
}