#pragma once
#include "ObjectTemplates/Actor.h"
#include "ECS/ProjectileComponent.h"
#include "ObjectTemplates/Projectile.h"

class Ship : public Actor
{
public:

	Ship()
	:m_Gun(nullptr){}
	Ship(int x, int y, Team team) 
	:m_Gun(nullptr) {}
	
	virtual ~Ship() {}

	virtual void InitComponents(int xPos, int yPos, int width, int height, float scale,float angle, float speed, float xVel, float yVel, float health, float damage) override;

	virtual void FireGun();

	std::vector<std::shared_ptr<Projectile>>& GetProjectileList()
	{
		return m_Gun->GetProjectileList();
	}

	inline bool IsReloading() { return m_Gun->reloading; }

	virtual void Update() override;

protected:

	ProjectileComponent* m_Gun;

private:

};

