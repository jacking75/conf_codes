
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

Particle* GetParticlePointer(std::shared_ptr<Particle>& ParticlePtr)
{
	return ParticlePtr.get();
}

int main()
{
	std::shared_ptr<Particle> ParticlePtr(new Particle(10));	
	
	// Particle 인스터스의 참조를 얻어서 직접 멤버 변수 사용
	Particle& ParticleRef = *ParticlePtr;
	std::cout << "ParticleRef의 ID: " << ParticleRef.m_nID << std::endl;

	// Particle 인스터스의 포인터를 얻어서 멤버 변수 사용
	Particle* pParticle = GetParticlePointer(ParticlePtr);
	std::cout << "pParticle의 ID: " << pParticle->m_nID << std::endl;

	// Particle1를 통해서 Particle 인스터스의 멤버 접근
	std::cout << "ParticlePtr의 ID: " << ParticlePtr->m_nID << std::endl;
	
	return 0;
}

            