#include "Spawner.h"

Spawner::Spawner(std::list<std::shared_ptr<GameObject>>* objectList)
	: m_ObjList(objectList)
{
	time(&previousTime);
}

Spawner::Spawner(std::list<GameObject*>* objectList)
	: m_ObjList_raw(objectList)
{
	time(&previousTime);
}

void Spawner::SpawnAsteroid()
{
	if (time(&currentTime) - previousTime >= 1)
	{
		int randx = rand() % 800;
		std::cout << "spawning asteroid\n";
		//Asteroid* tmp = new Asteroid(randx, 0);
		//m_ObjList_raw.push_back(tmp);
		m_ObjList_raw->emplace_back(new Asteroid(randx, 0));
		previousTime = currentTime;
	}
	//std::cout << m_ObjList_raw.size() << "in spawn " << std::endl;
}


