#include "Actor.h"

Actor::Actor()
{
	
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

void Actor::Update()
{		
	m_TransformComponent->Update();
	m_TextureComponent->Update();
}


