#include "Projectile.h"
#include "Vector2D.h"

Projectile::Projectile()
{
	//m_Team = team;
}

Projectile::~Projectile()
{
	std::cout << "destroyed projectile\n";
}

Projectile::Projectile(Vector2D position, int width, int height, float scale, int xVel, int yVel, float speed, float health, float damage, Team team)
{

	std::cout << "projectile const\n";
	m_Team = team;

	InitComponents(position.x, position.y, width, height, scale, xVel, yVel, speed, health, damage);
	
	// x,y,w,h,sc,speed,vx,vy,health, damage
	

	//InitComponents(position, dimensions, velocity, health, damage);
}


Projectile::Projectile(Vector2D position, Vector2D velocity, Team team)
{

	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Projectile_64.png";
	m_Team = team;
	InitComponents(position.x, position.y, 32, 32, 1, 2, velocity.x, velocity.y, 1, 1);

}


