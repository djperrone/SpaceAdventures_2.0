#pragma once
#include "GameObject.h"

#include "ECS/ComponentManager.h"
#include "ECS/ColliderComponent.h"
#include "ECS/CombatComponent.h"
#include "ECS/MovementComponent.h"


class Actor : public GameObject
{

public:
	Actor();	
	virtual ~Actor();

	virtual void Update() override;	
	virtual void UpdateLocation();

	virtual void Actor::InitComponents(const char* fileName, float xPos, float yPos, int width, int height, float scale, float angle) override;
	virtual void InitComponents(const char* fileName, int xPos, int yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage);



	float GetLeftBound() const;	
	float GetRightBound()const;
	float GetUpperBound()const;
	float GetLowerBound()const;	

	Tag GetTag() const;

protected:	
	ColliderComponent* m_ColliderComponent;	
	Tag m_Tag = Tag::None;	

private:
	

};

