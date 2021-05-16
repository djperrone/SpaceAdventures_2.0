#include "ShipProjectile.h"

ShipProjectile::ShipProjectile()
{
	m_Team = Team::Enemy;
	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Projectile_64.png";
	InitComponents(0, 0, 32, 32, 1,2, 0,1, 1,1);
}

ShipProjectile::~ShipProjectile()
{
	std::cout << "desotred shipprojectile\n";
}

ShipProjectile::ShipProjectile(Vector2D position, Vector2D velocity, Team team)
{
	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Projectile_64.png";
	InitComponents(position.x,position.y,32,32,1,2,velocity.x,velocity.y,1,1);
}

