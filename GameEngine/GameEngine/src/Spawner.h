#pragma once
#include <list>

#include "GameObject.h"
#include "Asteroid.h"
#include "Dimensions.h"
#include <time.h>

class Spawner
{
public:
	Spawner(std::list<GameObject*>* objList);
	Spawner(std::list<std::shared_ptr<GameObject>>* objList);

	void SpawnAsteroid();

private:
	std::list <std::shared_ptr<GameObject>>* m_ObjList;
	std::list <GameObject*>* m_ObjList_raw;
	Dimensions m_Dimensions;

	time_t currentTime;
	time_t previousTime;

	double ASTEROID_SPAWN_RATE = 1000;
};

