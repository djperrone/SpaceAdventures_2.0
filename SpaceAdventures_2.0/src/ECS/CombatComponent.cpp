#include "sapch.h"
#include "CombatComponent.h"
#include "ObjectTemplates/Actor.h"

void CombatComponent::Attack(Actor* actor)
{
	actor->TakeDamage(GetDamage());
}