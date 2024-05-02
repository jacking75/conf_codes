
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


int main()
{
	std::unique_ptr<Particle[]> ParticlePtr1( new Particle[3]);

	return 0;
}


