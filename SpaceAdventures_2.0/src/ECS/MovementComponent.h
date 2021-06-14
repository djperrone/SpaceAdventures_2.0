#pragma once
#include "Component.h"
#include "Vector2D.h"

class MovementComponent : public Component
{
public:
	COMPONENT_CLASS_TYPE(MovementComponent)

	MovementComponent();
	MovementComponent(float xVel, float yVel, float speed);
	virtual ~MovementComponent();
	float GetSpeed();
	void SetSpeed(float speed);
	Vector2D GetVelocityVec();
	float GetXVelocity() const;
	float GetYVelocity() const;
	void SetXVelocity(float xVel);
	void SetYVelocity(float yVel);

private:
	float m_Speed;
	Vector2D m_Velocity;
};
