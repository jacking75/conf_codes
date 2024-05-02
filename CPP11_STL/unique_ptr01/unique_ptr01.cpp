
#include <iostream>
#include <vector>
#include <memory>

class Particle
{
public:
	Particle(int nID)
	{
		m_nID = nID;
		std::cout << "Particle " << m_nID << "번 생성. " << std::endl;
	}

	~Particle()
	{
		std::cout << "Particle " << m_nID << "번 소멸. " << std::endl;
	}

	int m_nID;
};



int main()
{
	{
		std::unique_ptr<Particle> ParticlePtr( new Particle( 1 ));
	}

	std::unique_ptr<Particle> ParticlePtr1( new Particle( 11 ));
	
	std::vector<std::unique_ptr<Particle>> ParticlePtrs;

	std::cout << "컨테이너 ParticlePtrs에 ParticlePtr1 넣기" << std::endl;
	//ParticlePtrs.push_back( ParticlePtr1 );	// 컴파일 에러
	ParticlePtrs.push_back( std::move(ParticlePtr1) );

	if( ParticlePtr1.get() == nullptr )
	{
		std::cout << "ParticlePtr1에서 관리하는 객체 없음" << std::endl;
	}

	return 0;
}

