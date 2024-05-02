
#include <iostream>
#include <memory>

class Particle
{
public:
	Particle()
	{
		std::cout << "Particle 持失切" << std::endl;
	}

	~Particle()
	{
		std::cout << "Particle 社瑚切" << std::endl;
	}
};

void Deleter(Particle* pParticle) 
{
    std::cout << "Call Deleter:  Particle1" << std::endl;
	delete pParticle;
}

void DeleterArray(Particle* pParticle) 
{
    std::cout << "Call DeleterArray:  Particle1" << std::endl;
	delete[] pParticle;
}

int main()
{
	{
		std::unique_ptr<Particle, decltype(&Deleter)> ParticlePtr1( new Particle, Deleter);
	}
   
	{
		std::unique_ptr<Particle[], decltype(&DeleterArray)> ParticlePtr2( new Particle[3], DeleterArray );
	}

	return 0;
}

