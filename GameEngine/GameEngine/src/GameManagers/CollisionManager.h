#pragma once
#include <list>
#include <memory>
#include "ObjectTemplates/Actor.h"

class CollisionManager
{
public:
	CollisionManager(std::list<std::shared_ptr<Actor>>* objList);

	void Tick();
	bool IsColliding(Actor* current, Actor* other);
	void HandleCollisionEvent(Actor* current, Actor* other);
	bool IsOnSameTeam(Actor* current, Actor* other);


protected:
	
private:
	std::list<std::shared_ptr<Actor>>* m_ObjectList;
	//std::iterator<std::list<std::shared_ptr<Actor>> it;
};

