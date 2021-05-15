#pragma once

//#include "ObjectTemplates/Actor.h"
#include "Component.h"


class ColliderComponent : public Component
{
public:
	//ColliderComponent(int& x, int& y, float& width, float& height, float& scale )
	//	: m_TransformComponent(//:m_XPosition(x), m_YPosition(y), m_Width(width), m_Height(height), m_Scale(scale)//, m_Damage(1)
	//{
	//	std::cout << "collider comp\n";

	//	

	//}	

			ColliderComponent(TransformComponent* component)
		: m_TransformComponent(component)//:m_XPosition(x), m_YPosition(y), m_Width(width), m_Height(height), m_Scale(scale)//, m_Damage(1)
			{
				std::cout << "collider comp\n";



			}


	COMPONENT_CLASS_TYPE(ColliderComponent)

	float GetLeftBound()
	{
		return m_TransformComponent->GetXPosition();
	}
	float GetRightBound()
	{
		return m_TransformComponent->GetXPosition() + m_TransformComponent->GetWidth() * m_TransformComponent->GetScale();
	}

	float GetUpperBound()
	{
		return m_TransformComponent->GetYPosition() + m_TransformComponent->GetHeight() * m_TransformComponent->GetScale();
	}

	float GetLowerBound()
	{
		return m_TransformComponent->GetYPosition();
	}

private:
	TransformComponent* m_TransformComponent;

	//float m_LeftBound, m_RightBound, m_UpperBound, m_LowerBound;
	//float m_XPosition, m_YPosition;
	//float m_Scale;
	//int m_Width, m_Height;

	//float m_Damage;
};