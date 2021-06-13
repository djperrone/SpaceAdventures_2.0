#include "sapch.h"
#include "Level.h"
#include "GameManagers/ObjectManager.h"

Level::Level(SDL_Event* event)
{
	SDL_ShowCursor(false);
	m_ObjectManager = std::make_unique<ObjectManager>(event);	
}

Level::~Level()
{
}

void Level::Update()
{
	m_ObjectManager->Update();
}

void Level::Render(std::shared_ptr<Renderer>& renderer)
{
	m_ObjectManager->Render(renderer);
}
