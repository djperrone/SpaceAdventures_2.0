#pragma once
#include "Component.h"
#include "Math/Vector2d.h"

class TransformComponent : public Component
{
public:	

	COMPONENT_CLASS_TYPE(TransformComponent)

	TransformComponent(float xPos, float yPos, int width, int height, float scale);
	TransformComponent(float xPos, float yPos, int width, int height, float scale, float angle);	

	~TransformComponent()
	{
		/*std::cout << "Deleted transform component\n";*/
	}

	void Update() override
	{
		/*m_Position.x += m_Velocity.x * m_Speed;
		m_Position.y += m_Velocity.y * m_Speed;*/
	}	

	float GetXPosition() const { return m_Position.x; }
	float GetYPosition() const { return m_Position.y; }
	void SetXPosition(float xPos) {m_Position.x = xPos; }
	void SetYPosition(float yPos) { m_Position.y = yPos; }

	int GetWidth() const { return m_Width; }
	int GetHeight() const { return m_Height; }
	void SetWidth(int width) { m_Width = width; }
	void SetHeight(int height) { m_Height = height; }	

	float GetScale() const { return m_Scale; }
	void SetScale(float scale) { m_Scale = scale; }

	float GetAngle() const { return m_Angle; }
	void SetAngle(float angle) { m_Angle = angle; }

	Vector2D GetPositionVec() const { return m_Position; }	

private:

	Vector2D m_Position;	
	int m_Height;
	int m_Width;
	float m_Scale;
	float m_Angle;
};