#include "ObjectManager.h"



ObjectManager::ObjectManager(SDL_Event* event)
	: m_Event(event)
{
	std::cout << "constructed objmanager!\n";
	m_Player = std::make_shared<Player>();
	m_InputController = std::make_unique<KeyboardController>(m_Player.get());
	

	m_ObjectList.push_back(m_Player);
	
	m_CollisionManager = std::make_unique<CollisionManager>(&m_ObjectList);
	m_Spawner = std::make_unique<Spawner>(&m_ObjectList);
}

void ObjectManager::Render(std::shared_ptr<Renderer>& renderer)
{
	//renderer->Render(testB.get());
	//renderer->Render(m_Player.get());
	for (auto& obj : m_ObjectList)
	{
		//if(obj.get()->GetHealth()>0)
		renderer->Render(obj.get());
		//std::cout << obj->GetImageName() << std::endl;
		
	}
	//std::cout << m_ObjectList.size() << std::endl;
}

Player* ObjectManager::GetPlayer() const
{
	return m_Player.get();
}

void ObjectManager::Tick()
{
	//std::cout << "test in objmanager" << m_ObjectList.size() << std::endl;
	m_Spawner->SpawnAsteroid();
	m_CollisionManager->Tick();
	m_InputController->UpdateLocation(*m_Event);
	
	Update();
}

void ObjectManager::Update()
{
	CleanList();
	for (auto& obj : m_ObjectList)
	{
		obj->Update();
	}
}

void ObjectManager::CleanList()
{
	for (auto it = m_ObjectList.begin(); it != m_ObjectList.end(); )
	{
		if (!it->get()->IsAlive() || !IsWithinBounds(it->get()))
		{
			it = m_ObjectList.erase(it);
		}
		else
		{
			it++;
		}
	}
}

bool ObjectManager::IsWithinBounds(Actor* tempObject)
{
	if (tempObject->GetXPosition() < 0 || tempObject->GetYPosition() > dimensions.HEIGHT +200 ||
		tempObject->GetXPosition() > dimensions.WIDTH  || tempObject->GetYPosition() < -200)
	{
		std::cout<<("Destroyed asteroid/projectile\n");
		//tempObject.setHealth(0);
		return false;
	}

	return true;
}




