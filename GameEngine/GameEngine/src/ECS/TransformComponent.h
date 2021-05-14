#pragma once
#include "Component.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
private:

	Vector2D m_Position;
	Vector2D m_Velocity;

	int m_Height;
	int m_Width;
	float m_Scale;

	float m_Speed;
public:
	//ComponentType componentTypeID = ComponentType::TransformComponent;

	COMPONENT_CLASS_TYPE(TransformComponent)

		//static ComponentType GetStaticType() { return ComponentType::TransformComponent; }
		//ComponentType GetComponentType() const override {return GetStaticType();}
	

	TransformComponent(float x, float y, int w, int h, float sc, int speed) 
		:m_Position{ x,y }, m_Height(h), m_Width(w), m_Scale(sc), m_Speed(speed)
		
	{
		std::cout << "transform component!\n"; 
	}

	TransformComponent(float x, float y, int w, int h, float sc, int speed,float vx, float vy)
		:m_Position{ x,y }, m_Height(h), m_Width(w), m_Scale(sc),
		m_Speed(speed), m_Velocity(vx, vy){}
	~TransformComponent()
	{
		std::cout << "Deleted transform component\n";
	}

	void Update() override
	{
		m_Position.x += m_Velocity.x * m_Speed;
		m_Position.y += m_Velocity.y * m_Speed;
	}


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
	inline float SetSpeed(float speed) { m_Speed = speed; }

	inline float GetScale() const { return m_Scale; }
	inline float SetScale(float scale) { m_Scale = scale; }

};