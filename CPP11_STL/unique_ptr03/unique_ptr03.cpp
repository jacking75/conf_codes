
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
	std::cout << "release()" << std::endl;
	std::unique_ptr<Particle> ParticlePtr1( new Particle(1) );	
	ParticlePtr1.release();

	if( ParticlePtr1 == false )
	{
		std::cout << "ParticlePtr1 == false" << std::endl << std::endl;
	}


	std::cout << "reset(Particle(22))" << std::endl;
	std::unique_ptr<Particle> ParticlePtr2( new Particle(2) );
	ParticlePtr2.reset( new Particle(22) );
	std::cout << "ParticlePtr2의 ID: " << ParticlePtr2->m_nID << std::endl;
	
	std::cout << "reset()" << std::endl;
	ParticlePtr2.reset();
	
	if( ParticlePtr2 == false )
	{
		std::cout << "ParticlePtr2 == false" << std::endl << std::endl;
	}
		

	std::cout << "swap" << std::endl;
	std::shared_ptr<Particle> ParticlePtr3( new Particle(3) );	
	std::shared_ptr<Particle> ParticlePtr4( new Particle(4) );	
	
	ParticlePtr3.swap( ParticlePtr4 );

	std::cout << "ParticlePtr3의 ID: " << ParticlePtr3->m_nID << std::endl;
	std::cout << "ParticlePtr4의 ID: " << ParticlePtr4->m_nID << std::endl;
	return 0;
}


