#include "sapch.h"

#include "ObjectManager.h"
#include "MyObjects/ReloadIcon.h"
#include "MyObjects/MouseCursor.h"
#include "MyObjects/Player.h"
#include "MyObjects/Asteroid.h"
#include "MyObjects/Projectile.h"




ObjectManager::ObjectManager(SDL_Event* event, InputController* inputController)
	: m_Event(event), isFirst(true)
{
	std::cout << "constructed objmanager!\n";
	
	m_MouseController = std::make_unique<MouseCursor>();
	m_ReloadIcon = std::make_unique<ReloadIcon>();

	m_Player = std::make_shared<Player>(m_MouseController.get(), inputController);	

	m_ObjectList.push_back(m_Player);
	m_ShipList.push_back(m_Player);
	
	m_CollisionManager = std::make_unique<CollisionManager>(&m_ObjectList, &m_AsteroidList);
	m_Spawner = std::make_unique<Spawner>(&m_ObjectList, &m_ShipList,&m_AsteroidList);

	m_ProjectileManager = std::make_unique<ProjectileManager>();	
}

void ObjectManager::Render(std::shared_ptr<Renderer>& renderer)
{
	if (m_Player->IsReloading())
	{
		renderer->Render(m_ReloadIcon.get());
	}

	for (auto& obj : m_ProjectileList)
	{		
		renderer->Render(obj.get());		
	}

	for (auto& obj : m_AsteroidList)
	{		
		renderer->Render(obj.get());		
	}
	for (auto& obj : m_ShipList)
	{		
		renderer->Render(obj.get());		
	}

	renderer->Render(m_MouseController.get());	
}




void ObjectManager::Update()
{
	if (!m_Player->IsAlive())
	{
		std::cout << "player dead!\n";
	}

	m_Spawner->SpawnAsteroid();
	m_Spawner->SpawnUFO();
	
	m_MouseController->Update();
	m_ReloadIcon->Update();	

	for (auto& obj : m_ProjectileList)
	{
		//std::cout << "updating\n";
		obj->Update();
	}

	for (auto& obj : m_AsteroidList)
	{
		obj->Update();
	}
	for (auto& obj : m_ShipList)
	{		
		//std::cout << "updating\n";
		obj->Update();
	}

	m_CollisionManager->Tick();
	LoadAllProjectiles();
	CleanList();
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

	for (auto it = m_AsteroidList.begin(); it != m_AsteroidList.end(); )
	{
		if (!it->get()->IsAlive() || !IsWithinBounds(it->get()))
		{
			it = m_AsteroidList.erase(it);
		}
		else
		{
			it++;
		}
	}

	for (auto it = m_ShipList.begin(); it != m_ShipList.end(); )
	{
		if (!it->get()->IsAlive() || !IsWithinBounds(it->get()))
		{
			it = m_ShipList.erase(it);
		}
		else
		{
			it++;
		}
	}

	for (auto it = m_ProjectileList.begin(); it != m_ProjectileList.end(); )
	{
		if (!it->get()->IsAlive() || !IsWithinBounds(it->get()))
		{
			it = m_ProjectileList.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void ObjectManager::LoadAllProjectiles()
{	
	m_ProjectileManager->LoadAllProjectiles(m_ShipList);
	auto list = m_ProjectileManager->GetProjectileList();
	std::copy(list.begin(), list.end(), std::back_inserter(m_ObjectList));
	std::copy(list.begin(), list.end(), std::back_inserter(m_ProjectileList));
	m_ProjectileManager->ClearProjectileList();
}

bool ObjectManager::IsWithinBounds(Character* tempObject)
{
	if (tempObject->GetXPosition() < -100 || tempObject->GetYPosition() > dimensions.HEIGHT +200 ||
		tempObject->GetXPosition() > dimensions.WIDTH  || tempObject->GetYPosition() < -200)
	{	
		return false;
	}

	return true;
}

Player* ObjectManager::GetPlayer()
{
	return m_Player.get();
}




