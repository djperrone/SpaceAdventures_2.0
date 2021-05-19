#pragma once
#include "ObjectTemplates/Projectile.h"


class ShipProjectile : public Projectile
{
public:
	ShipProjectile();
	~ShipProjectile();

	ShipProjectile(Vector2D position, float direction, Vector2D velocity, Team team, float angle);
	

	
};

