#include "sapch.h"
#include "Ship.h"

void Ship::InitComponents(int xPos, int yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage)
{
	m_ComponentManager = std::make_unique<ComponentManager>();

	m_ComponentManager->AddComponent<TransformComponent>(xPos, yPos, width, height, scale,angle, speed, xVel, yVel);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();

	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();

	m_ComponentManager->AddComponent<ColliderComponent>(m_TransformComponent);
	m_ColliderComponent = &m_ComponentManager->GetComponent<ColliderComponent>();

	m_ComponentManager->AddComponent<CombatComponent>(health, damage);
	m_CombatComponent = &m_ComponentManager->GetComponent<CombatComponent>();

	m_ComponentManager->AddComponent<ProjectileComponent>(m_TransformComponent,m_Team);
	m_Gun = &m_ComponentManager->GetComponent<ProjectileComponent>();
}

void Ship::FireGun()
{
	m_Gun->FireGun();
}

void Ship::Update()
{
	std::cout << "updating\n";

	m_TransformComponent->Update();
	m_TextureComponent->Update();
	m_Gun->Update();
}
