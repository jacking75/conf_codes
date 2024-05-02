
#include <iostream>
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
	std::shared_ptr<Particle> ParticlePtr( new Particle(10) );	
	std::cout << "ParticlePtr의 ID: " << ParticlePtr->m_nID << std::endl;

	std::cout << "reset - 다른 인스턴스로 교체" << std::endl;
	ParticlePtr.reset( new Particle(11) );
	std::cout << "ParticlePtr의 ID: " << ParticlePtr->m_nID << std::endl;
	
	std::cout << "reset - 인스턴스 삭제" << std::endl;
	ParticlePtr.reset();
	std::cout << "ParticlePtr의 참조 수: " << ParticlePtr.use_count() << std::endl;
	
	return 0;
}

            