#pragma once
#include <list>

#include "ObjectTemplates/GameObject.h"
#include "MyObjects/Asteroid.h"
#include "MyObjects/Ship.h"
#include "MyObjects/UFO.h"
#include "Dimensions.h"
#include <vector>



class Actor;
class Asteroid;
class Ship;
class Spawner
{
public:
	//Spawner(std::list<GameObject*>* objList);
	Spawner(std::list<std::shared_ptr<Actor>>* objectList, std::list<std::shared_ptr<Ship>>* shipList, std::list<std::unique_ptr<Asteroid>>* asteroidList);

	void SpawnAsteroid();
	void SpawnUFO();


	template <typename T>
	void Spawn()
	{
		
		//T* temp1 = new T();

	
	/*	std::shared_ptr<T> temp = std::make_shared<T>();
		if (temp.get()->GetTag() == Tag::Ship)
		{
			m_ShipList->push_back((temp));

		}

		m_ObjList->push_back(std::move(temp));*/


	}

private:
	std::list <std::shared_ptr<Actor>>* m_ObjList;
	std::list <std::shared_ptr<Ship>>* m_ShipList;
	std::list <std::unique_ptr<Asteroid>>* m_AsteroidList;
	//std::list <GameObject*>* m_ObjList_raw;
	Dimensions m_Dimensions;

	time_t currentTime;
	time_t previousTime;

	time_t ufoCurrentTime;
	time_t ufoPreviousTime;
	double UFO_SPAWN_RATE = 5000;

	double ASTEROID_SPAWN_RATE = 1000;
};

