#include "CollisionManager.h"


CollisionManager::CollisionManager(std::list<std::shared_ptr<Actor>>* objList)
	: m_ObjectList(objList)
{

}

void CollisionManager::Tick()
{
	//std::cout << "col man tick " <<(m_ObjectList->size())<<"\n";
	for (auto it = std::begin(*m_ObjectList); it != std::end(*m_ObjectList); it++)
	{
		for (auto otherIt = std::begin(*m_ObjectList); otherIt != std::end(*m_ObjectList); otherIt++)
		{
			if (IsColliding(it->get(), otherIt->get()) && !IsOnSameTeam(it->get(), otherIt->get()))
			{
				HandleCollisionEvent(it->get(), otherIt->get());
				std::cout << "collision!\n";
			}
		}	
		
	}

	/*for (int i = 0; i < m_ObjectList.size(); i++)
	{
		
	}*/


}

void CollisionManager::HandleCollisionEvent(Actor* current, Actor* other)
{
	std::cout << "collission detected!\n";
	current->Attack(other);
	//other->Attack(current);
}

bool CollisionManager::IsOnSameTeam(Actor* current, Actor* other)
{
	//std::cout << "current team: " << static_cast<std::size_t>(current->GetTeam()) << ", other team: " << static_cast<std::size_t>(other->GetTeam()) << std::endl;
	return current->GetTeam() == other->GetTeam();
}


bool CollisionManager::IsColliding(Actor* current, Actor* other)
{
	if (current->GetRightBound() >= other->GetLeftBound() &&
		other->GetRightBound() >= current->GetLeftBound() &&
		current->GetUpperBound() >= other->GetLowerBound() &&
		other->GetUpperBound() >= current->GetLowerBound())
	{
		return true;
	}

	return false;
}