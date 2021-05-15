#pragma once
#include "GameObject.h"
#include "ECS/ComponentManager.h"
#include "ECS/ColliderComponent.h"
#include "ECS/CombatComponent.h"
#define PI 3.14159265358979323846

class Actor : public GameObject
{

public:
	Actor();
	Actor(int x, int y);
	Actor(const std::string& texturesheet, int x, int y);
	virtual void InitComponents(int x, int y) override;


	~Actor();

	void Update() override;	
	virtual void InitComponents() override;
	virtual void InitComponents(float xPos, float yPos, int width, int height, float scale, float speed, float xVel, float yVel, float health, float damage) override;

	//virtual void InitComponents(const std::string& texturesheet, int x, int y, float width, float height, float scale, float speed) override;

	//inline bool IsCollidable() const { return collidable; }
	
	float GetLeftBound() const;	
	float GetRightBound()const;
	float GetUpperBound()const;
	float GetLowerBound()const;
	
	inline float GetHealth() const { return m_CombatComponent->GetHealth(); }
	inline float GetDamage() const { return m_CombatComponent->GetDamage(); }

	inline void TakeDamage(float damage) { m_CombatComponent->TakeDamage(damage); }
	inline void Attack(Actor* actor) { actor->TakeDamage(GetDamage()); }

	inline Team GetTeam()const { return team; }

	inline bool IsAlive() const { return GetHealth() > 0; }

protected:

	CombatComponent* m_CombatComponent;
	Team team = Team::None;
	//bool collidable;

	//float m_Health;

private:
	//collision component
	

};

