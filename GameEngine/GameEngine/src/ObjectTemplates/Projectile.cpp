#include "Projectile.h"
#include "Vector2D.h"

Projectile::Projectile()
{
}

Projectile::~Projectile()
{
}

Projectile::Projectile(Vector2D position, int width, int height, float scale, int xVel, int yVel, float speed, float health, float damage, Team team)
{
	m_Team = team;

	InitComponents(position.x, position.y, width, height, scale, xVel, yVel, speed, health, damage);
	
	// x,y,w,h,sc,speed,vx,vy,health, damage
	

	//InitComponents(position, dimensions, velocity, health, damage);
}


Projectile::Projectile(Vector2D position, Vector2D velocity, Team team)
{
	InitComponents(position.x, position.y, 32, 32, 1, 2, velocity.x, velocity.y, 1, 1);

}


