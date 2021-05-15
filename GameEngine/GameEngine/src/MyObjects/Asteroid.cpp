#include "Asteroid.h"

Asteroid::Asteroid()
{
	std::cout << "Asteroid!\n";

	m_ImageName = "D:/Dev/Asteroid_old/GameEngine/GameEngine/assets/Asteroid1.png";
	// x,y,w,h,sc,speed,vx,vy,health, damage
	InitComponents(0,0,32,32,1,3,0,1,1,1);	
}

Asteroid::Asteroid(int x, int y)
{
	team = Team::Enemy;
	std::cout << "Asteroid!" << static_cast<std::size_t>(team) << std::endl;

	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Asteroid1.png";
	InitComponents(x, y, 32, 32, 2, 3, 0, 1,1,1);
}

Asteroid::~Asteroid() {}


