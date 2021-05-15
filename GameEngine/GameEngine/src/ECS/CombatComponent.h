#pragma once
//#include "ObjectTemplates/Actor.h"
//class Actor;
class CombatComponent : public Component
{
public:
	CombatComponent()
		:m_Health(1), m_Damage(0) {}
	

	CombatComponent(float health, float damage)
		: m_Health(health), m_Damage(damage) {
		std::cout << "combat comp\n";
	}


	inline void TakeDamage(float damage)
	{
		m_Health -= damage;
	}

	//inline void Attack(Actor* actor)
	//{
	//	actor->TakeDamage(GetDamage());
	//}

	COMPONENT_CLASS_TYPE(CombatComponent)

	inline float GetHealth() const { return m_Health; }
	inline float GetDamage() const { return m_Damage; }
	inline void SetHealth(float health) { m_Health = health; }
	inline void SetDamage(float damage) { m_Damage = damage; }
		
private:
	float m_Health, m_Damage;
};