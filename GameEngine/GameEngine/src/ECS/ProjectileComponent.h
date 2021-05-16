#pragma once
#include "Component.h"
#include "TransformComponent.h"

#include <vector>

//class Projectile;
#include "../ObjectTemplates/Projectile.h"

class ProjectileComponent : public Component
{
public:
	ProjectileComponent(TransformComponent* transform, Team& team)
		:m_TransformComponent(transform), m_Team(team)
	{
	}

	void FireGun()
	{
		/*m_ProjectileList.emplace_back(new Projectile(m_TransformComponent->GetPositionVec(),
									m_TransformComponent->GetVelocityVec(),m_Team));*/
		m_ProjectileList.emplace_back(std::move(std::make_shared<Projectile>(m_TransformComponent->GetPositionVec(),
			m_TransformComponent->GetVelocityVec(), m_Team)));

		//std::cout << "projectilecomponent fire gun list size: "<<m_ProjectileList.size()<<"~\n";

	}
	void ClearGun()
	{
		m_ProjectileList.clear();
	}

	inline std::vector<std::shared_ptr<Projectile>>& GetProjectileList() { return m_ProjectileList; }

	COMPONENT_CLASS_TYPE(ProjectileComponent)


protected:
	std::vector<std::shared_ptr<Projectile>> m_ProjectileList;
	TransformComponent* m_TransformComponent;
	Team m_Team;

};