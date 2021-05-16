#pragma once
#include "ObjectTemplates/Actor.h"
#include "ECS/ProjectileComponent.h"
#include "MyObjects/ShipProjectile.h"

class Ship : public Actor
{
public:

	Ship() {}
	Ship(int x, int y, Team team) {}
	
	virtual ~Ship() {}

	virtual void InitComponents(float xPos, float yPos, int width, int height, float scale, float speed, float xVel, float yVel, float health, float damage) override;

	virtual void FireGun();
	std::vector<std::shared_ptr<Projectile>>& GetProjectileList()
	{
		return m_Gun->GetProjectileList();
	}


protected:

	ProjectileComponent* m_Gun;

private:

};

