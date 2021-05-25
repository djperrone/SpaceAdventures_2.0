#include "GameManager.h"

#include "Game.h"

GameManager::GameManager(Game* game, SDL_Renderer* renderer, SDL_Event* event)
	: m_Event(event), m_Game(game)
{
	//m_TextureManager = std::make_unique<TextureManager>();
	//m_GameplayManager = std::make_unique<GamePlayManager>();
	m_ObjectManager = std::make_unique<ObjectManager>(event);	
	m_Renderer = std::make_shared<Renderer>(renderer);
	"game manager const!\n";
}

void GameManager::Render()
{
	//m_Renderer->Render(m_ObjectManager->GetPlayer());	
	m_ObjectManager->Render(m_Renderer);
}

void GameManager::Tick()
{
	if (!m_ObjectManager->GetPlayer()->IsAlive())
	{
		m_Game->isRunning = false;
	}

	m_ObjectManager->Tick();
}

