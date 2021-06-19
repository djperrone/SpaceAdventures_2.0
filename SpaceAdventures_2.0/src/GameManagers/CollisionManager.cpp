
#include "sapch.h"
#include "Math/Vector2d.h"
#include "CollisionManager.h"

#include "ObjectTemplates/Character.h"
#include "ObjectTemplates/GameObject.h"
#include "MyObjects/Asteroid.h"


CollisionManager::CollisionManager(std::list<std::shared_ptr<Character>>* objList, std::list<std::unique_ptr<Asteroid>>* asteroidList)
	: m_ObjectList(objList), m_AsteroidList(asteroidList)
{

}

CollisionManager::CollisionManager()
	: m_AsteroidList(nullptr), m_ObjectList(nullptr)
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

		for (auto otherIt = std::begin(*m_AsteroidList); otherIt != std::end(*m_AsteroidList); otherIt++)
		{
			if (IsColliding(it->get(), otherIt->get()) && !IsOnSameTeam(it->get(), otherIt->get()))
			{
				HandleCollisionEvent(it->get(), otherIt->get());
				std::cout << "collision!\n";
			}
		}
		
	}

	for (auto it = std::begin(*m_AsteroidList); it != std::end(*m_AsteroidList); it++)
	{
		//std::cout << "Asteroidsadasdasdasd\n";
		for (auto otherIt = std::begin(*m_AsteroidList); otherIt != std::end(*m_AsteroidList); otherIt++)
		{
			if (IsColliding(it->get(), otherIt->get()) && !IsOnSameTeam(it->get(), otherIt->get()))
			{
				HandleCollisionEvent(it->get(), otherIt->get());
				std::cout << "collision!\n";
			}
		}

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

void CollisionManager::HandleCollisionEvent(Character* current, Character* other)
{
	std::cout << "collission detected!\n";
	current->Attack(other);
	//other->Attack(current);
}

bool CollisionManager::IsOnSameTeam(Character* current, Character* other)
{
	//std::cout << "current team: " << static_cast<std::size_t>(current->GetTeam()) << ", other team: " << static_cast<std::size_t>(other->GetTeam()) << std::endl;
	return current->GetTeam() == other->GetTeam();
}


bool CollisionManager::IsColliding(Character* current, Character* other)
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

bool CollisionManager::IsColliding(Actor* current, Vector2i pos)
{
	if (pos.x >= current->GetLeftBound() &&
		pos.x <= current->GetRightBound() &&
		pos.y >= current->GetLowerBound() &&
		pos.y <= current->GetUpperBound())
	{
		return true;
	}
	return false;
}
