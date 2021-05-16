#pragma once
#include "ObjectTemplates/Projectile.h"


class ShipProjectile : public Projectile
{
public:
	ShipProjectile();
	~ShipProjectile();

	ShipProjectile(Vector2D position, Vector2D velocity, Team team);
	

	
};

