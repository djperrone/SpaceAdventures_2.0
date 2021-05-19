#include "ShipProjectile.h"

ShipProjectile::ShipProjectile()
{
	m_Team = Team::None;
	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Projectile_64.png";


	//InitComponents(0, 0, 1,32, 32, 1,2, 0,1, 1,1);
	//float xPos, float yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage


	//if (m_Team == Team::Enemy)
	//{
	//	InitComponents(0,0, 32, 32, 2, 3, 0, -1, 1, 1);

	//}
	//else
	//{
	//	InitComponents(0, 0, 32, 32, 2, 3, 0, 1, 1, 1);

	//}
}

ShipProjectile::~ShipProjectile()
{
	std::cout << "asdasddesotred shipprojectile\n";
}

ShipProjectile::ShipProjectile(Vector2D position, float direction, Vector2D velocity,Team team, float angle)
{
	m_Team = team;
	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Projectile_64.png";
	//InitComponents(position.x,position.y,direction,32,32,1,2,velocity.x,velocity.y,1,1);

	//float xPos, float yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage


	if (m_Team == Team::Enemy)
	{
		InitComponents(position.x, position.y, 32, 32, 2.0f,angle, 3.0f, 0.0f, 1.0f, 1.0f, 1.0f);

	}
	else
	{
		InitComponents(position.x, position.y, 32, 32, 2.0f, angle, 3.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	}
}

