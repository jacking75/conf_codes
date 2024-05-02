
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
	std::shared_ptr<Particle> Particle1(new Particle(1));	// 참조 수 1
	std::cout << "Particle1의 참조 수: " << Particle1.use_count() << std::endl;
	
	{
		std::shared_ptr<Particle> Particle2 = Particle1;		// 참조 수 2
		std::cout << "Particle1의 참조 수: " << Particle1.use_count() << std::endl;
		std::cout << "Particle2의 참조 수: " << Particle2.use_count() << std::endl;
	}

	// Particle2는 스코프를 벗어나면서 파괴되어 Particle1의 참조 수는 1
	std::cout << "Particle1의 참조 수: " << Particle1.use_count() << std::endl;

	// Particle1가 파괴되면서 참조 수는 0 이되면서 자동으로 메모리 해제
	return 0;
}

            