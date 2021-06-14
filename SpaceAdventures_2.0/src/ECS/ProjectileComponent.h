#pragma once
#include "Component.h"
#include "../MyObjects/Projectile.h"
class MovementComponent;

class TransformComponent;

class ProjectileComponent : public Component
{
public:
	COMPONENT_CLASS_TYPE(ProjectileComponent)
	ProjectileComponent(TransformComponent* transform, MovementComponent* movement, Team& team);
	void Reload();		
	virtual void Update() override;
	void FireGun();	
	void ClearGun();
	inline std::vector<std::shared_ptr<Projectile>>& GetProjectileList() { return m_ProjectileList; }

	bool reloading;
protected:
	std::vector<std::shared_ptr<Projectile>> m_ProjectileList;
	TransformComponent* m_TransformComponent;
	MovementComponent* m_MovementComponent;
	Team m_Team;
	Uint32 currentTime = 0;
	Uint32 previousTime = 0;
	Uint32 ReloadStartTime = 0;
	Uint32 fireRate = 250;

	int m_MagazineSize = 10;
	int m_UseCount = 0;

	Uint32 m_ReloadTime = 2500;
	

};