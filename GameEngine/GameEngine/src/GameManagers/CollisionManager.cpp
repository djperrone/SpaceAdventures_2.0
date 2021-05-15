#include "CollisionManager.h"


CollisionManager::CollisionManager(std::list<std::shared_ptr<Actor>>* objList)
	//: m_ObjectList(objList)
{

}

void CollisionManager::Tick()
{/*
	for (auto it = std::begin(*m_ObjectList); it != std::end(*m_ObjectList); it++)
	{
		for (auto otherIt = ++it; otherIt != std::end(*m_ObjectList); otherIt++)
		{
			if (IsColliding(it->get(), otherIt->get()))
			{
				HandleCollisionEvent(it->get(), otherIt->get());
			}
		}
	}*/
}

void CollisionManager::HandleCollisionEvent(Actor* current, Actor* other)
{

}


bool CollisionManager::IsColliding(Actor* current, Actor* other)
{
	/*if (current->GetRightBound() >= other->GetLeftBound() &&
		other->GetRightBound() >= current->GetLeftBound() &&
		current->GetUpperBound() >= other->GetLowerBound() &&
		other->GetUpperBound() >= current->GetLowerBound())
	{
		return true;
	}*/

	return false;
}