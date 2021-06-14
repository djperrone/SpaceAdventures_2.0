#pragma once
#include "Component.h"

class TransformComponent;

class ColliderComponent : public Component
{
public:
	ColliderComponent(TransformComponent* component);
	
	COMPONENT_CLASS_TYPE(ColliderComponent)

	float GetLeftBound();
	float GetRightBound();
	float GetUpperBound();
	float GetLowerBound();

private:
	TransformComponent* m_TransformComponent;	
};