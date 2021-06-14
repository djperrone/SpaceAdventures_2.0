#include "sapch.h"
#include "Ship.h"

void Ship::InitGun()
{
	m_ComponentManager->AddComponent<ProjectileComponent>(m_TransformComponent,m_MovementComponent, m_Team);
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
