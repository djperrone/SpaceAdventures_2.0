#pragma once
#include "ObjectTemplates/Actor.h"
#include "ECS/ProjectileComponent.h"
#include "MyObjects/ShipProjectile.h"

class Ship : public Actor
{
public:

	

protected:

	std::unique_ptr<ProjectileComponent> m_Gun;

private:

};

