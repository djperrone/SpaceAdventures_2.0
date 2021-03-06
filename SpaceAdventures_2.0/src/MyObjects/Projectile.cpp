#include "sapch.h"
#include "Projectile.h"
#include "Math/Vector2d.h"

Projectile::Projectile()
{
	//m_Team = team;
}

Projectile::~Projectile()
{
	std::cout << "destroyed projectile\n";
}

Projectile::Projectile(Vector2D position, Vector2D velocity, Team team, float angle)
{
	if (team == Team::Friend)
	{
		m_ImageName = "assets/Projectile_64.png";
	}
	else
	{
		m_ImageName = "assets/Projectile_64_enemy.png";

	}
	m_Team = team;

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
	//std::cout << "angle " << GetAngle() << std::endl;

	float yRad = sin(GetAngle() * 3.14159 / 180.0f);
	float xRad = cos(GetAngle() * 3.14159 / 180.0f);

	SetYVelocity(yRad);
	SetXVelocity(xRad);
	
	UpdateLocation();
	m_TextureComponent->Update();
}


