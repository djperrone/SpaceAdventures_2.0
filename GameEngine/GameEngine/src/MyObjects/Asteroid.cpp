#include "Asteroid.h"

Asteroid::Asteroid()
{
	std::cout << "Asteroid!\n";
	int randx = rand() % 800;
	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Asteroid1.png";
	// x,y,w,h,sc,speed,vx,vy,health, damage

	if (m_Team == Team::Enemy)
	{
		InitComponents(randx, 0, 32, 32, 2.0f,0.0f, 3.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	}
	else
	{
		InitComponents(randx, 0, 32, 32, 2.0f, 0.0f, 3.0f, 0.0f, 1.0f, 1.0f, 1.0f);

	}
	//InitComponents(0, 0, 32, 32, 2, 3, 0, 1, 1, 1);
	m_Team = Team::Enemy;
}

Asteroid::Asteroid(int x, int y)
{
	m_Team = Team::Enemy;
	std::cout << "Asteroid!" << static_cast<std::size_t>(m_Team) << std::endl;

	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Asteroid1.png";
	if (m_Team == Team::Enemy)
	{
		InitComponents(x, y, 32, 32, 2.0f, 0.0f, 1.5f, 0.0f, 1.0f, 1.0f, 1.0f);

	}
	/*else
	{
		InitComponents(x, y, 32, 32, 2.0f, 0.0f, 3.0f, 0.0f, 1.0f, 1.0f, 1.0f);

	}*/
}

Asteroid::~Asteroid() { std::cout<<"destroyed asteroid\n"; }


