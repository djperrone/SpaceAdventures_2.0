#pragma once
#include "Component.h"
#include "TransformComponent.h"

#include <vector>
#include <time.h>
#include "SDL.h"

//class Projectile;
#include "../ObjectTemplates/Projectile.h"

class ProjectileComponent : public Component
{
public:
	ProjectileComponent(TransformComponent* transform, Team& team)
		:m_TransformComponent(transform), m_Team(team)
	{
		previousTime = SDL_GetTicks();
		previousTime -= fireRate;
		reloading = false;
	}

	void Reload()
	{
		if(!reloading)
			reloading = true;

		if (SDL_GetTicks() - previousTime <= m_ReloadTime)
		{
			return;
		}
		else
		{
			m_UseCount = 0;
			reloading = false;
		}
	}

	void FireGun()
	{
		if (m_UseCount >= m_MagazineSize)
		{
			Reload();
		}

		if (reloading)
		{
			Reload();
			return;
		}

		if (!reloading)
		{
			currentTime = SDL_GetTicks();
			if (currentTime - previousTime >= fireRate)
			{
				m_ProjectileList.emplace_back(std::move(std::make_shared<Projectile>(m_TransformComponent->GetPositionVec(),
					m_TransformComponent->GetVelocityVec(), m_TransformComponent->GetDirection(), m_Team, m_TransformComponent->GetAngle())));

				previousTime = currentTime;

				m_UseCount++;
			}
		}

		
		/*m_ProjectileList.emplace_back(new Projectile(m_TransformComponent->GetPositionVec(),
									m_TransformComponent->GetVelocityVec(),m_Team));*/
		

		//std::cout << "projectilecomponent fire gun list size: "<<m_ProjectileList.size()<<"~\n";

	}
	void ClearGun()
	{
		m_ProjectileList.clear();
	}

	inline std::vector<std::shared_ptr<Projectile>>& GetProjectileList() { return m_ProjectileList; }

	COMPONENT_CLASS_TYPE(ProjectileComponent)


	bool reloading;
protected:
	std::vector<std::shared_ptr<Projectile>> m_ProjectileList;
	TransformComponent* m_TransformComponent;
	Team m_Team;
	Uint32 currentTime;
	Uint32 previousTime;
	double fireRate = 250;


	int m_MagazineSize = 10;
	int m_UseCount = 0;

	Uint32 m_ReloadTime = 1000;
	

};