#pragma once
#include "Actor.h"

#include "ECS/ComponentManager.h"
#include "ECS/ColliderComponent.h"
#include "ECS/CombatComponent.h"
#include "ECS/MovementComponent.h"


class Character : public Actor
{

public:
	Character();
	virtual ~Character();

	virtual void Update() override;
	virtual void UpdateLocation();

	virtual void InitComponents(int xPos, int yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage);
	virtual void InitComponents(const char* fileName, int xPos, int yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage);

	float GetXVelocity() const;
	float GetYVelocity() const;
	void SetXVelocity(float xVelocity);
	void SetYVelocity(float yVelocity);
	float GetSpeed() const;
	void SetSpeed(float speed);
	Vector2D GetVelocityVec() const;

	float GetLeftBound() const;
	float GetRightBound()const;
	float GetUpperBound()const;
	float GetLowerBound()const;

	float GetHealth() const;
	float GetDamage() const;

	void TakeDamage(float damage);
	void Attack(Character* Character);
	bool IsAlive() const;

	Team GetTeam()const;
	Tag GetTag() const;

protected:
	MovementComponent* m_MovementComponent;
	CombatComponent* m_CombatComponent;
	ColliderComponent* m_ColliderComponent;
	Team m_Team;
	Tag m_Tag = Tag::None;

private:


};

