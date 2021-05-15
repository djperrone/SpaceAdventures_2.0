//#pragma once
//
//#include "ObjectTemplates/Actor.h"
//class ColliderComponent
//{
//public:
//	ColliderComponent(int& x, int& y, float& width, float& height, float& scale )
//		:m_XPosition(x), m_YPosition(y), m_Width(width), m_Height(height), m_Scale(scale), m_Damage(1)
//	{
//		std::cout << "collider comp\n";
//
//		
//
//	}	
//
//	float GetLeftBound()
//	{
//		return m_XPosition;
//	}
//	float GetRightBound()
//	{
//		return m_XPosition + m_Width * m_Scale;
//	}
//
//	float GetUpperBound()
//	{
//		return m_YPosition + m_Height * m_Scale;
//	}
//
//	float GetLowerBound()
//	{
//		return m_YPosition;
//	}
//
//private:
//	//TransformComponent* m_TransformComponent;
//
//	float m_LeftBound, m_RightBound, m_UpperBound, m_LowerBound;
//	float m_XPosition, m_YPosition;
//	float m_Scale;
//	int m_Width, m_Height;
//
//	float m_Damage;
//};