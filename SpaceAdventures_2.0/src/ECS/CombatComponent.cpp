#include "sapch.h"
#include "CombatComponent.h"
#include "ObjectTemplates/Character.h"

void CombatComponent::Attack(Character* Character)
{
	Character->TakeDamage(GetDamage());
}