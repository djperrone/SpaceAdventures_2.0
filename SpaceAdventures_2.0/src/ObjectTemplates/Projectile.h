#pragma once
#include "ObjectTemplates/Actor.h"

class Vector2D;

class Projectile : public Actor
{
public:
	Projectile();
	
	Projectile(Vector2D position, Vector2D velocity, float direction, Team team, float angle);

	void Update() override;

	virtual ~Projectile();


protected:

};

