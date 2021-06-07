
#include "sapch.h"
#include "ProjectileComponent.h"

#include <time.h>
#include "TransformComponent.h"



ProjectileComponent::ProjectileComponent(TransformComponent* transform, Team& team)
	:m_TransformComponent(transform), m_Team(team)
{
	previousTime = SDL_GetTicks();
	previousTime -= fireRate;
	reloading = false;
}

void ProjectileComponent::Reload()
{
	if (!reloading)
	{
		ReloadStartTime = SDL_GetTicks();
		reloading = true;
	}
}

void ProjectileComponent::Update()
{
	if (reloading)
	{
		if (SDL_GetTicks() - ReloadStartTime > m_ReloadTime)		
		{
			m_UseCount = 0;
			reloading = false;
		}
	}

}

void ProjectileComponent::FireGun()
{

	if (!reloading)
	{
		if (m_UseCount >= m_MagazineSize)
		{
			Reload();
		}


		currentTime = SDL_GetTicks();
		if (currentTime - previousTime >= fireRate)
		{
			Vector2D spawnLoc = { m_TransformComponent->GetPositionVec() };
			spawnLoc.x += (m_TransformComponent->GetWidth() * m_TransformComponent->GetScale()) / 2.0f - 10;
			spawnLoc.y += (m_TransformComponent->GetHeight() * m_TransformComponent->GetScale()) / 2.0f;

			m_ProjectileList.emplace_back(std::move(std::make_shared<Projectile>(spawnLoc,
				m_TransformComponent->GetVelocityVec(), m_TransformComponent->GetDirection(), m_Team, m_TransformComponent->GetAngle())));

			previousTime = currentTime;

			m_UseCount++;
		}

	}

}
void ProjectileComponent::ClearGun()
{
	m_ProjectileList.clear();
}