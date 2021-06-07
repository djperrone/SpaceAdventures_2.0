#pragma once
#include "GameObject.h"
#include "ECS/ComponentManager.h"
#include "ECS/ColliderComponent.h"
#include "ECS/CombatComponent.h"


class Actor : public GameObject
{

public:
	Actor();
	Actor(int x, int y);
	Actor(const std::string& texturesheet, int x, int y);
	virtual ~Actor();

	virtual void Update() override;		
	
	void InitComponents(int xPos, int yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage) override;

	float GetLeftBound() const;	
	float GetRightBound()const;
	float GetUpperBound()const;
	float GetLowerBound()const;
	
	inline float GetHealth() const { return m_CombatComponent->GetHealth(); }
	inline float GetDamage() const { return m_CombatComponent->GetDamage(); }

	inline void TakeDamage(float damage) { m_CombatComponent->TakeDamage(damage); }
	inline void Attack(Actor* actor) { m_CombatComponent->Attack(actor); } 
	inline bool IsAlive() const { return GetHealth() > 0; }

	inline Team GetTeam()const { return m_Team; }

	inline Tag GetTag() const { return m_Tag; }


protected:

	CombatComponent* m_CombatComponent;
	Team m_Team;
	Tag m_Tag = Tag::None;
	

private:
	
	

};

