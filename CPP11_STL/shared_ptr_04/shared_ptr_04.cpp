
#include <iostream>
#include <memory>

class Particle
{
public:
	Particle(int nID) { m_nID = nID; }

	~Particle() {}

	int m_nID;
};

int main()
{
	std::shared_ptr<Particle> ParticlePtr1( new Particle(10) );	
	std::cout << "ParticlePtr1의 ID: " << ParticlePtr1->m_nID << std::endl;

	std::shared_ptr<Particle> ParticlePtr2( new Particle(20) );	
	std::cout << "ParticlePtr2의 ID: " << ParticlePtr2->m_nID << std::endl;

	std::cout << "swap 사용" << std::endl;
	ParticlePtr1.swap( ParticlePtr2 );

	std::cout << "ParticlePtr1의 ID: " << ParticlePtr1->m_nID << std::endl;
	std::cout << "ParticlePtr2의 ID: " << ParticlePtr2->m_nID << std::endl;
	
	return 0;
}

            