#pragma once
#include <list>
#include <memory>
#include "ObjectTemplates/Actor.h"
#include "MyObjects/Asteroid.h"


class CollisionManager
{
public:
	CollisionManager(std::list<std::shared_ptr<Actor>>* objList, std::list<std::unique_ptr<Asteroid>>* asteroidList);

	void Tick();
	bool IsColliding(Actor* current, Actor* other);
	void HandleCollisionEvent(Actor* current, Actor* other);
	bool IsOnSameTeam(Actor* current, Actor* other);


protected:
	
private:
	std::list<std::shared_ptr<Actor>>* m_ObjectList;
	std::list<std::unique_ptr<Asteroid>>* m_AsteroidList;
	//std::iterator<std::list<std::shared_ptr<Actor>> it;
};

