#include "sapch.h"
#include "TransformComponent.h"

TransformComponent::TransformComponent(float xPos, float yPos, int width, int height, float scale)
	:m_Position(xPos,yPos),m_Width(width), m_Height(height), m_Scale(scale), m_Angle(0)
{
}

TransformComponent::TransformComponent(float xPos, float yPos, int width, int height, float scale, float angle)
	: m_Position(xPos,yPos), m_Width(width), m_Height(height), m_Scale(scale), m_Angle(angle)
{
}
