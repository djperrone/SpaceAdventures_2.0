#pragma once
#include "ObjectTemplates/Character.h"

class Vector2D;

class Projectile : public Character
{
public:
	Projectile();
	
	Projectile(Vector2D position, Vector2D velocit, Team team, float angle);

	void Update() override;

	virtual ~Projectile();


protected:

};

