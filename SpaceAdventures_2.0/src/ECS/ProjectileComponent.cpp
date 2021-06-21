#include "sapch.h"
#include "SDL.h"

#include "ProjectileComponent.h"
#include "TransformComponent.h"
#include "MovementComponent.h"

ProjectileComponent::ProjectileComponent(TransformComponent* transform, MovementComponent* movement, Team& team)
	:m_TransformComponent(transform), m_MovementComponent(movement), m_Team(team)
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

bool ProjectileComponent::FireGun()
{

	if (!reloading)
	{
		if (m_UseCount >= m_MagazineSize)
		{
			Reload();
			return false;
		}


		currentTime = SDL_GetTicks();
		if (currentTime - previousTime >= fireRate)
		{
			Vector2D spawnLoc = { m_TransformComponent->GetPositionVec() };
			spawnLoc.x += (m_TransformComponent->GetWidth() * m_TransformComponent->GetScale()) / 2.0f - 10;
			spawnLoc.y += (m_TransformComponent->GetHeight() * m_TransformComponent->GetScale()) / 2.0f;

			m_ProjectileList.emplace_back(std::move(std::make_shared<Projectile>(spawnLoc,
				m_MovementComponent->GetVelocityVec(), m_Team, m_TransformComponent->GetAngle())));

			previousTime = currentTime;

			m_UseCount++;
		}
		return true;
	}
	return false;
}
void ProjectileComponent::ClearGun()
{
	m_ProjectileList.clear();
}

void ProjectileComponent::LoadProjectile()
{
}
