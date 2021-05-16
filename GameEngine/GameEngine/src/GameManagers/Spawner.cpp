#include "Spawner.h"


Spawner::Spawner(std::list<std::shared_ptr<Actor>>* objectList, std::list<std::shared_ptr<Ship>>* shipList)
	: m_ObjList(objectList), m_ShipList(shipList)
{
	time(&previousTime);
}

//Spawner::Spawner(std::list<GameObject*>* objectList)
//	: m_ObjList_raw(objectList)
//{
//	time(&previousTime);
//}

void Spawner::SpawnAsteroid()
{
	if (time(&currentTime) - previousTime >= 1)
	{
		int randx = rand() % 800;
		//std::cout << "spawning asteroid\n";
		//Asteroid* tmp = new Asteroid(randx, 0);
		//m_ObjList_raw.push_back(tmp);
		std::shared_ptr<Asteroid> ast = std::make_shared<Asteroid>();
		//std::shared_ptr<Asteroid> ast = std::make_shared<Asteroid>(randx, 0);
		//Asteroid* test = new Asteroid(1, 1);
		m_ObjList->push_back(ast);
		previousTime = currentTime;
	}
	//std::cout << m_ObjList_raw.size() << "in spawn " << std::endl;
}

//void Spawner::SpawnShip()
//{
//	int randx = rand() % 800;
//	int y = 0;
//	std::shared_ptr<Ship> ast = std::make_shared<Ship>(randx,y);
//}

void Spawner::SpawnUFO()
{
	int randx = rand() % 800;
	int y = 0;
	std::shared_ptr<UFO> ufo = std::make_shared<UFO>(randx, y);

	m_ObjList->push_back((ufo));
	m_ShipList->push_back(std::move(ufo));
}

