#pragma once
#include "ObjectTemplates/Character.h"
#include "ECS/ProjectileComponent.h"
#include "MyObjects/Projectile.h"

class Ship : public Character
{
public:

	Ship()
	:m_Gun(nullptr){}
	Ship(int x, int y, Team team) 
	:m_Gun(nullptr) {}
	
	virtual ~Ship() {}

	virtual void InitGun();
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

