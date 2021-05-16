#include "ObjectManager.h"



ObjectManager::ObjectManager(SDL_Event* event)
	: m_Event(event)
{
	std::cout << "constructed objmanager!\n";
	m_Player = std::make_shared<Player>();
	m_InputController = std::make_unique<KeyboardController>(m_Player.get());
	

	m_ObjectList.push_back((m_Player));
	m_ShipList.push_back(m_Player);
	
	m_CollisionManager = std::make_unique<CollisionManager>(&m_ObjectList);
	m_Spawner = std::make_unique<Spawner>(&m_ObjectList, &m_ShipList);

	m_ProjectileManager = std::make_unique<ProjectileManager>();
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
	if (!m_Player->IsAlive())
	{
		//std::cout << "player dead!\n";
		//exit;
	}
	LoadAllProjectiles();

	//m_Spawner->SpawnAsteroid();
	if (m_ObjectList.size() <5)
	{
	std::cout << "test in objmanager" << m_ObjectList.size() << std::endl;
		//std::cout << "player health " << m_Player.get()->GetHealth() << std::endl;

	//m_Spawner->Spawn<ShipProjectile>();
		//m_Spawner->SpawnUFO();
	}
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
}

void ObjectManager::LoadAllProjectiles()
{

	//std::cout << "projectile list size " << m_ProjectileManager->GetProjectileList().size() << std::endl;
	m_ProjectileManager->LoadAllProjectiles(m_ShipList);
	//std::cout <<"obj manager proj list size "<< m_ProjectileManager->GetProjectileList().size() << std::endl;
	//m_ObjectList.insert(m_ObjectList.end(), m_ProjectileManager->GetProjectileList().begin(), m_ProjectileManager->GetProjectileList().begin());
	auto list = m_ProjectileManager->GetProjectileList();
	std::copy(list.begin(), list.end(), std::back_inserter(m_ObjectList));
	m_ProjectileManager->ClearProjectileList();
}

bool ObjectManager::IsWithinBounds(Actor* tempObject)
{
	if (tempObject->GetXPosition() < -100 || tempObject->GetYPosition() > dimensions.HEIGHT +200 ||
		tempObject->GetXPosition() > dimensions.WIDTH  || tempObject->GetYPosition() < -200)
	{
		//std::cout<<(tempObject->GetImageName());
		//tempObject.setHealth(0);
		return false;
	}

	return true;
}




