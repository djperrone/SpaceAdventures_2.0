#include "UFO.h"

UFO::UFO()
{
	m_Team = Team::Enemy;
	m_Tag = Tag::Ship;
	std::cout << "UFO!\n";
	int randx = rand() % 800;
	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/UFO.png";
	InitComponents(randx, 0, 32, 32, 2, 3, 0, 0, 1, 1);

}

UFO::~UFO()
{
	std::cout << "destroyed ufo\n";
}

UFO::UFO(float x, float y)
{
	m_Tag = Tag::Ship;
	m_Team = Team::Enemy;
	std::cout << "Asteroid!" << static_cast<std::size_t>(m_Team) << std::endl;

	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/UFO.png";
	InitComponents(x, y, 32, 32, 2, 3, 0,0, 1, 1);
}
