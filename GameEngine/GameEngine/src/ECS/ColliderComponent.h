#pragma once

#include "../Actor.h"
class ColliderComponent
{
public:
	ColliderComponent(TransformComponent* transformComponent )
		: m_TransformComponent(transformComponent)
	{
		std::cout << "collider comp\n";
	}

private:
	TransformComponent* m_TransformComponent;
};