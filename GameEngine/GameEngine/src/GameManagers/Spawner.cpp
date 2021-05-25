#include "Spawner.h"


Spawner::Spawner(std::list<std::shared_ptr<Actor>>* objectList, std::list<std::shared_ptr<Ship>>* shipList, std::list<std::unique_ptr<Asteroid>>* asteroidList)
	: m_ObjList(objectList), m_ShipList(shipList), m_AsteroidList(asteroidList)
{
	time(&previousTime);
	time(&ufoPreviousTime);
}

void Spawner::SpawnAsteroid()
{
	if (time(&currentTime) - previousTime >= 1)
	{
		int randx = rand() % 800;

		 m_AsteroidList->emplace_back(std::move(std::make_unique<Asteroid>(randx,-100)));
		 std::cout << "asteorielist size " << m_AsteroidList->size() << std::endl;
		previousTime = currentTime;
	}
	
}


void Spawner::SpawnUFO()
{
	int randx = rand() % 800;
	int y = 0;

	time(&ufoCurrentTime);
	if ( ufoCurrentTime- ufoPreviousTime >= 5 && m_ShipList->size() < 3)
	{
		int randx = rand() % 800;
		std::shared_ptr<UFO> tempUFO = std::make_shared<UFO>(randx,0);
		m_ObjList->push_back(tempUFO);
		m_ShipList->push_back(std::move(tempUFO));
		ufoPreviousTime = ufoCurrentTime;
	}
}

void Spawner::SpawnUFO(int x, int y)
{
	//int randx = rand() % 800;
	//int y = 0;
	//std::cout << "overloaded ufo spawn\n";
	//time(&ufoCurrentTime);
	if (m_ShipList->size() < 3)
	{
		
		std::shared_ptr<UFO> tempUFO = std::make_shared<UFO>(x, y);
		m_ObjList->push_back(tempUFO);
		m_ShipList->push_back(std::move(tempUFO));
		ufoPreviousTime = ufoCurrentTime;
	}
}

