#include "sapch.h"
#include "Character.h"


Character::Character()
	:m_CombatComponent(nullptr)
{
}

Character::~Character() { std::cout << "desoyed Character\n"; }

void Character::InitComponents(int xPos, int yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage)
{
	m_ComponentManager = std::make_unique<ComponentManager>();

	m_ComponentManager->AddComponent<TransformComponent>(xPos, yPos, width, height, scale, angle);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();

	m_ComponentManager->AddComponent<MovementComponent>(xVel, yVel, speed);
	m_MovementComponent = &m_ComponentManager->GetComponent<MovementComponent>();

	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();

	m_ComponentManager->AddComponent<ColliderComponent>(m_TransformComponent);
	m_ColliderComponent = &m_ComponentManager->GetComponent<ColliderComponent>();

	m_ComponentManager->AddComponent<CombatComponent>(health, damage);
	m_CombatComponent = &m_ComponentManager->GetComponent<CombatComponent>();
}

void Character::InitComponents(const char* fileName, int xPos, int yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage)
{
}

void Character::Update()
{
	/*m_Position.x += m_Velocity.x * m_Speed;
		m_Position.y += m_Velocity.y * m_Speed;*/
	UpdateLocation();
	//m_TransformComponent->Update();
	m_TextureComponent->Update();
}

void Character::UpdateLocation()
{
	SetXPosition(GetXPosition() + GetXVelocity() * GetSpeed());
	SetYPosition(GetYPosition() + GetYVelocity() * GetSpeed());
}

float Character::GetLeftBound() const
{
	return m_ComponentManager->GetComponent<ColliderComponent>().GetLeftBound();
}
float Character::GetRightBound()const
{
	return m_ComponentManager->GetComponent<ColliderComponent>().GetRightBound();
}

float Character::GetUpperBound()const
{
	return m_ComponentManager->GetComponent<ColliderComponent>().GetUpperBound();
}

float Character::GetLowerBound()const
{
	return m_ComponentManager->GetComponent<ColliderComponent>().GetLowerBound();
}

float Character::GetXVelocity() const { return m_MovementComponent->GetXVelocity(); }
float Character::GetYVelocity() const { return m_MovementComponent->GetYVelocity(); }
void Character::SetXVelocity(float xVelocity) { m_MovementComponent->SetXVelocity(xVelocity); }
void Character::SetYVelocity(float yVelocity) { m_MovementComponent->SetYVelocity(yVelocity); }
float Character::GetSpeed() const { return m_MovementComponent->GetSpeed(); }
void Character::SetSpeed(float speed) { m_MovementComponent->SetSpeed(speed); }
Vector2D Character::GetVelocityVec() const { return m_MovementComponent->GetVelocityVec(); }
float Character::GetHealth() const { return m_CombatComponent->GetHealth(); }
float Character::GetDamage() const { return m_CombatComponent->GetDamage(); }
void Character::TakeDamage(float damage) { m_CombatComponent->TakeDamage(damage); }
void Character::Attack(Character* Character) { m_CombatComponent->Attack(Character); }
bool Character::IsAlive() const { return GetHealth() > 0; }
Team Character::GetTeam()const { return m_Team; }
Tag Character::GetTag() const { return m_Tag; }

