#include "Spawner.h"


Spawner::Spawner(std::list<std::shared_ptr<Actor>>* objectList)
	: m_ObjList(objectList)
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


