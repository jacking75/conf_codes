
#include <iostream>
#include <memory>

class Particle
{
public:
	Particle()
	{
		std::cout << "Particle 积己磊" << std::endl;
	}

	~Particle()
	{
		std::cout << "Particle 家戈磊" << std::endl;
	}
};



int main()
{
	{
		std::shared_ptr<Particle> ParticlePtr1( new Particle, 
											[] (Particle* pParticle){
                                                  std::cout << "Call Deleter:  Particle1" << std::endl;
                                                  delete pParticle;
                                             });
	}
   
	{
		std::cout << "硅凯 按眉" << std::endl;
		std::shared_ptr<Particle> ParticlePtr2( new Particle[3], 
											[] (Particle* pParticle){
                                                  std::cout << "Call Deleter:  Particle2" << std::endl;
                                                  delete[] pParticle;
                                             });
	}

	return 0;
}




