#pragma once
#include "Component.h"
#include "../Vector2D.h"
//#include "../ObjectTemplates/ObjectDimensions.h"



class TransformComponent : public Component
{
public:	

	COMPONENT_CLASS_TYPE(TransformComponent)
		

	TransformComponent(float x, float y, float direction,int w, int h, float sc, float speed)
		:m_Position{ x,y }, m_Height(h), m_Width(w), m_Direction(direction), m_Scale(sc), m_Speed(speed),m_Angle(0){}	

	TransformComponent(int w, int h, float sc)
		:m_Height(h), m_Width(w),  m_Scale(sc),m_Angle(0),m_Direction(0),m_Speed(0)

	{
		std::cout << "transform component!\n";
	}

	TransformComponent(int w, int h, float sc, float x, float y)
		:m_Height(h), m_Width(w), m_Scale(sc), m_Angle(0), m_Position{x,y}, m_Speed(0),m_Direction(0)

	{
		std::cout << "transform component! rea\n";
		std::cout << "x " << m_Position.x << ' ' << m_Position.y << std::endl;
	}

	

	TransformComponent(float x, float y, int w, int h, float sc,float angle, float speed, float vx, float vy)
		:m_Position{ x,y }, m_Height(h), m_Width(w), m_Scale(sc),
		m_Velocity{ vx, vy }, m_Speed(speed), m_Direction(1),m_Angle(angle) {}

	~TransformComponent()
	{
		std::cout << "Deleted transform component\n";
	}

	void Update() override
	{
		m_Position.x += m_Velocity.x * m_Speed;
		m_Position.y += m_Velocity.y * m_Speed;
	}	

	inline float GetDirection() const { return m_Direction; }
	inline float GetXVelocity() const { return m_Velocity.x; }
	inline float GetYVelocity() const { return m_Velocity.y; }
	inline void SetXVelocity(float xVelocity) { m_Velocity.x = xVelocity; }
	inline void SetYVelocity(float yVelocity) { m_Velocity.y = yVelocity; }

	inline float GetXPosition() const { return m_Position.x; }
	inline float GetYPosition() const { return m_Position.y; }
	inline void SetXPosition(float xPos) {m_Position.x = xPos; }
	inline void SetYPosition(float yPos) { m_Position.y = yPos; }

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline void SetWidth(int width) { m_Width = width; }
	inline void SetHeight(int height) { m_Height = height; }
	inline float GetSpeed() const { return m_Speed; }
	inline void SetSpeed(float speed) { m_Speed = speed; }

	inline float GetScale() const { return m_Scale; }
	inline void SetScale(float scale) { m_Scale = scale; }

	inline float GetAngle() const { return m_Angle; }
	inline void SetAngle(float angle) { m_Angle = angle; }

	inline Vector2D GetPositionVec() const { return m_Position; }
	inline Vector2D GetVelocityVec() const { return m_Velocity; }

private:

	Vector2D m_Position;
	Vector2D m_Velocity;

	float m_Direction;
	int m_Height;
	int m_Width;
	float m_Scale;
	float m_Angle;

	float m_Speed;

};