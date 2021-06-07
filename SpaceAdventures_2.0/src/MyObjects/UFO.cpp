
#include "sapch.h"
#include "UFO.h"

UFO::UFO()
{
	m_Team = Team::Enemy;
	m_Tag = Tag::Ship;
	std::cout << "UFO!\n";
	int randx = rand() % 800;
	m_ImageName = "assets/UFO.png";
	InitComponents(randx, 0, 32, 32, 2.0f, 1.0f, 3.0f, 0.0f, 0.0f, 3.0f, 1.0f);
	time(&previousTime);
}

UFO::~UFO()
{
	std::cout << "destroyed ufo\n";
}

UFO::UFO(int x, int y)
{
	m_Tag = Tag::Ship;
	m_Team = Team::Enemy;
	std::cout << "Asteroid!" << static_cast<std::size_t>(m_Team) << std::endl;

	m_ImageName = "assets/UFO.png";
	//float xPos, float yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage

	InitComponents(x, y,32, 32, 2.5f, 90.0f, 3.0f, 0.0f,0.0f, 3.0f, 1.0f);
}

void UFO::Update()
{
	m_TransformComponent->Update();
	m_TextureComponent->Update();

	time(&currentTime);
	if (currentTime - previousTime >= 2)
	{
		
		FireGun();
		previousTime = currentTime;
	}
}
