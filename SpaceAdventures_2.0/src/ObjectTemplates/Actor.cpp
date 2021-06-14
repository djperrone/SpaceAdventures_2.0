#include "sapch.h"
#include "Actor.h"


Actor::Actor()
{	
}

Actor::~Actor() { /*std::cout << "desoyed Actor\n";*/ }

void Actor::InitComponents(const char* fileName, float xPos, float yPos, int width, int height, float scale, float angle)
{
	m_ComponentManager = std::make_unique<ComponentManager>();
	m_ComponentManager->AddComponent<TransformComponent>(xPos, yPos, width, height, scale, angle);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
	m_ComponentManager->AddComponent<TextureComponent>(fileName, m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();

	m_ComponentManager->AddComponent<ColliderComponent>(m_TransformComponent);
	m_ColliderComponent = &m_ComponentManager->GetComponent<ColliderComponent>();
}


void Actor::InitComponents(const char* fileName, int xPos, int yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage)
{
	m_ComponentManager = std::make_unique<ComponentManager>();

	m_ComponentManager->AddComponent<TransformComponent>(xPos, yPos, width, height, scale,angle);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();	

	m_ComponentManager->AddComponent<TextureComponent>(fileName, m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();

	m_ComponentManager->AddComponent<ColliderComponent>(m_TransformComponent);
	m_ColliderComponent = &m_ComponentManager->GetComponent<ColliderComponent>();	
}



void Actor::Update()
{		
	/*m_Position.x += m_Velocity.x * m_Speed;
		m_Position.y += m_Velocity.y * m_Speed;*/
	UpdateLocation();
	//m_TransformComponent->Update();
	m_TextureComponent->Update();
}

void Actor::UpdateLocation()
{
	//SetXPosition(GetXPosition() + GetXVelocity() * GetSpeed());
	//SetYPosition(GetYPosition() + GetYVelocity() * GetSpeed());
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
Tag Actor::GetTag() const { return m_Tag; }

