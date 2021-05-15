#include "ObjectManager.h"


ObjectManager::ObjectManager(SDL_Event* event)
	: m_Event(event)
{
	std::cout << "constructed objmanager!\n";
	m_Player = std::make_shared<Player>();
	m_InputController = std::make_unique<KeyboardController>(m_Player.get());
	//m_ObjectList.push_back(m_Player);

	m_ObjectList_raw.push_back(m_Player.get());
	
	//testA = new Asteroid(0,0);
	//testB = std::make_shared<Asteroid>();
	//m_Spawner = std::make_unique<Spawner>(&m_ObjectList);
	m_Spawner = std::make_unique<Spawner>(&m_ObjectList_raw);
}

void ObjectManager::Render(std::shared_ptr<Renderer>& renderer)
{
	//renderer->Render(testB.get());
	//renderer->Render(m_Player.get());
	for (auto& obj : m_ObjectList_raw)
	{
		renderer->Render(obj);
		//std::cout << obj->GetImageName() << std::endl;
		
	}
	std::cout << m_ObjectList_raw.size() << std::endl;
}

Player* ObjectManager::GetPlayer() const
{
	return m_Player.get();
}

void ObjectManager::Tick()
{
	//m_ObjectList_raw.emplace_back(new Asteroid(100, 0));
	m_Spawner->SpawnAsteroid();
	m_InputController->UpdateLocation(*m_Event);
	//m_Player->Update();
	//testA->Update();
	//testB->Update();
	Update();
}

void ObjectManager::Update()
{
	for (auto& obj : m_ObjectList_raw)
	{
		obj->Update();
	}
}


