#include "Actor.h"

Actor::Actor()
{
	//collidable = true;
}

Actor::Actor(int x, int y)
{

}
Actor::Actor(const std::string& texturesheet, int x, int y)
{

}

Actor::~Actor() {}


void Actor::InitComponents()
{
	/*m_ComponentManager = std::make_unique<ComponentManager>();
	m_ComponentManager->AddComponent<TransformComponent>(0, 0, 32, 32, 4, 5);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();*/

}

void Actor::InitComponents(int x, int y)
{
	/*m_ComponentManager = std::make_unique<ComponentManager>();
	m_ComponentManager->AddComponent<TransformComponent>(0, 0, 32, 32, 4, 5);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();*/

}

void Actor::InitComponents(float xPos, float yPos, int width, int height, float scale, float speed, float xVel, float yVel, float health, float damage)
{
	m_ComponentManager = std::make_unique<ComponentManager>();

	m_ComponentManager->AddComponent<TransformComponent>(xPos, yPos, width, height, scale, speed, xVel, yVel);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();

	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();

	m_ComponentManager->AddComponent<ColliderComponent>(m_TransformComponent);
	m_ColliderComponent = &m_ComponentManager->GetComponent<ColliderComponent>();

	m_ComponentManager->AddComponent<CombatComponent>(health,damage);
	m_CombatComponent = &m_ComponentManager->GetComponent<CombatComponent>();
}

void Actor::Update()
{		
	m_TransformComponent->Update();
	m_TextureComponent->Update();
}

float Actor::GetLeftBound() const
{
	return m_ComponentManager->GetComponent<ColliderComponent>().GetLeftBound();
}
float Actor::GetRightBound()const
{
	return m_ComponentManager->GetComponent<ColliderComponent>().GetRightBound();

}

float Actor::GetUpperBound()const
{
	return m_ComponentManager->GetComponent<ColliderComponent>().GetUpperBound();

}

float Actor::GetLowerBound()const
{
	return m_ComponentManager->GetComponent<ColliderComponent>().GetLowerBound();
}


