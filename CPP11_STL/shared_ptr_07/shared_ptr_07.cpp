
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
	std::shared_ptr<Particle> m_Other;
};



int main()
{
	std::shared_ptr<Particle> ParticlePtr1( new Particle( 1 ));
    {
		std::shared_ptr<Particle> ParticlePtr2( new Particle( 2 ));
		ParticlePtr1->m_Other = ParticlePtr2;  
		ParticlePtr2->m_Other = ParticlePtr1; 
     
		std::cout << "ParticlePtr1의 ID: " << ParticlePtr1->m_nID << std::endl;
		std::cout << "ParticlePtr2의 ID: " << ParticlePtr2->m_nID << std::endl;
    }
   
	std::cout << "ParticlePtr1의 ID: " << ParticlePtr1->m_nID << std::endl;
   
	return 0;
}
