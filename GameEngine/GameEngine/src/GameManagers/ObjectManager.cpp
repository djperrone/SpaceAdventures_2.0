#include "ObjectManager.h"



ObjectManager::ObjectManager(SDL_Event* event)
	: m_Event(event)
{
	std::cout << "constructed objmanager!\n";
	
	m_MouseController = std::make_unique<MouseCursor>();
	m_ReloadIcon = std::make_unique<ReloadIcon>();

	m_Player = std::make_shared<Player>(m_MouseController.get());
	m_InputController = std::make_unique<KeyboardController>(m_Player.get());

	m_ObjectList.push_back((m_Player));
	m_ShipList.push_back(m_Player);
	
	m_CollisionManager = std::make_unique<CollisionManager>(&m_ObjectList, &m_AsteroidList);
	m_Spawner = std::make_unique<Spawner>(&m_ObjectList, &m_ShipList,&m_AsteroidList);

	m_ProjectileManager = std::make_unique<ProjectileManager>();

	
}

void ObjectManager::Render(std::shared_ptr<Renderer>& renderer)
{
	//renderer->Render(testB.get());
	//renderer->Render(m_Player.get());

	if (m_Player->IsReloading())
	{
		renderer->Render(m_ReloadIcon.get());

	}

	for (auto& obj : m_ObjectList)
	{
		//if(obj.get()->GetHealth()>0)
		renderer->Render(obj.get());
		//std::cout << obj->GetImageName() << std::endl;
		
	}

	for (auto& obj : m_AsteroidList)
	{
		//if(obj.get()->GetHealth()>0)
		renderer->Render(obj.get());
		//std::cout << obj->GetImageName() << std::endl;
	}
	for (auto& obj : m_ShipList)
	{
		//if(obj.get()->GetHealth()>0)
		//renderer->Render(obj.get());
		//std::cout << obj->GetImageName() << std::endl;
	}

	renderer->Render(m_MouseController.get());

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
		std::cout << "player dead!\n";
		
		exit;
	}
	

	m_Spawner->SpawnAsteroid();
	m_Spawner->SpawnUFO();
	//m_Spawner->SpawnUFO(500, 500);
	if (m_ShipList.size() <3)
	{


		//m_AsteroidList.emplace_back(std::move(std::make_unique<Asteroid>()));
		//std::cout << "test in objmanager" << m_ObjectList.size() << std::endl;
		//std::cout << "player health " << m_Player.get()->GetHealth() << std::endl;

		//m_Spawner->Spawn<Asteroid>();
		//m_Spawner->SpawnUFO(100, 100);
	}
	m_CollisionManager->Tick();
	m_InputController->UpdateLocation(*m_Event);
	m_MouseController->Tick();
	m_ReloadIcon->Tick();
	
	Update();
	LoadAllProjectiles();
	//m_Player->Update();

}

void ObjectManager::Update()
{
	CleanList();
	for (auto& obj : m_ObjectList)
	{
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




