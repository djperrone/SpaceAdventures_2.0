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

//Projectile::Projectile(Vector2D position, float direction, int width, int height, float scale, int xVel, int yVel, float speed, float health, float damage, Team team)
//{
//
//	std::cout << "projectile const\n";
//	m_Team = team;
//
//	InitComponents(position.x + width * scale / 2 + 5, position.y + width * scale / 2 + 2, direction,width, height, scale, xVel, yVel, speed, health, damage);
//	
//	// x,y,w,h,sc,speed,vx,vy,health, damage
//	
//
//	//InitComponents(position, dimensions, velocity, health, damage);
//}


//Projectile::Projectile(Vector2D position, Vector2D velocity, float direction,Team team)
//{
//	if (team == Team::Friend)
//	{
//		m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Projectile_64.png";
//	}
//	else
//	{
//		m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Projectile_64_enemy.png";
//
//	}
//	m_Team = team;
//	//InitComponents(position.x, position.y, 32, 32, 1, 2, velocity.x, velocity.y, 1, 1);
//	//InitComponents(position.x, position.y, 32, 32, 1, 2, 0, direction, 1, 1);
//	int width = 32;
//	int height = 32;
//	int scale = 2;
//
//	if (m_Team == Team::Enemy)
//	{
//		InitComponents(position.x + width * scale /2 - 10, position.y+50, width, height, 1, 3, 0, 1, 1, 1);
//	}
//	else
//	{
//		InitComponents(position.x + width * scale / 2 + 15, position.y, width, height, 1, 3, 0, -1, 1, 1);
//
//	}
//
//}

Projectile::Projectile(Vector2D position, Vector2D velocity, float direction, Team team, float angle)
{
	if (team == Team::Friend)
	{
		m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Projectile_64.png";
	}
	else
	{
		m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Projectile_64_enemy.png";

	}
	m_Team = team;
	//InitComponents(position.x, position.y, 32, 32, 1, 2, velocity.x, velocity.y, 1, 1);
	//InitComponents(position.x, position.y, 32, 32, 1, 2, 0, direction, 1, 1);
	int width = 32;
	int height = 32;
	int scale = 2;

	if (m_Team == Team::Enemy)
	{
		InitComponents(position.x, position.y, width, height, 1.0f,angle, 1.5f, 0.0f, 1.0f, 1.0f, 1.0f);
		//(float xPos, float yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage) override;

	}
	else
	{
		
		InitComponents(position.x, position.y, width, height, 1.0f,angle, 3.0f, 0.0f, -1.0f, 1.0f, 1.0f);
		SetXVelocity(cos(GetAngle()));
		SetYVelocity((sin(GetAngle())));

	}

}

void Projectile::Update()
{
	std::cout << "angle " << GetAngle() << std::endl;
	//SetXVelocity((cos(GetAngle()*PI/180)));
	//SetYVelocity(((sin(GetAngle() * PI / 180))));

	float yRad = sin(GetAngle() * PI / 180.0f);
	float xRad = cos(GetAngle() * PI / 180.0f);

	SetYVelocity(yRad);
	SetXVelocity(xRad);


	
	std::cout <<"sin angle "<< sin(GetAngle() * PI / 180) << std::endl;

	std::cout << "y vel" << GetYVelocity() << std::endl;
	//SetXVelocity(GetSpeed()) ;
	//SetYVelocity(GetSpeed());
	m_TransformComponent->Update();
	m_TextureComponent->Update();
}


