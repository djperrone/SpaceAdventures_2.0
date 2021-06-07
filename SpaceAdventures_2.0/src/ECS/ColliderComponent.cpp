#include "sapch.h"
#include "ColliderComponent.h"
#include "TransformComponent.h"

ColliderComponent::ColliderComponent(TransformComponent* component)
	: m_TransformComponent(component)
{	
}

float ColliderComponent::GetLeftBound()
{
	return m_TransformComponent->GetXPosition();
}
float ColliderComponent::GetRightBound()
{
	return m_TransformComponent->GetXPosition() + m_TransformComponent->GetWidth() * m_TransformComponent->GetScale();
}

float ColliderComponent::GetUpperBound()
{
	return m_TransformComponent->GetYPosition() + m_TransformComponent->GetHeight() * m_TransformComponent->GetScale();
}

float ColliderComponent::GetLowerBound()
{
	return m_TransformComponent->GetYPosition();
}