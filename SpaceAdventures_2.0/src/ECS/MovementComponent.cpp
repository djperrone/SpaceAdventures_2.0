#include "sapch.h"
#include "MovementComponent.h"

MovementComponent::MovementComponent()
{
}

MovementComponent::MovementComponent(float xVel, float yVel, float speed)
	: m_Velocity(xVel,yVel), m_Speed(speed)
{
}

MovementComponent::~MovementComponent()
{
}

float MovementComponent::GetSpeed()
{
	return m_Speed;
}

void MovementComponent::SetSpeed(float speed)
{
	m_Speed = speed;
}
Vector2D MovementComponent::GetVelocityVec()
{
	return m_Velocity;
}

float MovementComponent::GetXVelocity() const
{
	return m_Velocity.x;
}

float MovementComponent::GetYVelocity() const
{
	return m_Velocity.y;

}

void MovementComponent::SetXVelocity(float xVel)
{
	m_Velocity.x = xVel;
}

void MovementComponent::SetYVelocity(float yVel)
{
	m_Velocity.y = yVel;
}
