#pragma once
#include <list>

#include "ObjectTemplates/GameObject.h"
#include "MyObjects/Asteroid.h"
#include "Dimensions.h"

class Actor;
class Asteroid;

class Spawner
{
public:
	//Spawner(std::list<GameObject*>* objList);
	Spawner(std::list<std::shared_ptr<Actor>>* objList);

	void SpawnAsteroid();

private:
	std::list <std::shared_ptr<Actor>>* m_ObjList;
	//std::list <GameObject*>* m_ObjList_raw;
	Dimensions m_Dimensions;

	time_t currentTime;
	time_t previousTime;

	double ASTEROID_SPAWN_RATE = 1000;
};

