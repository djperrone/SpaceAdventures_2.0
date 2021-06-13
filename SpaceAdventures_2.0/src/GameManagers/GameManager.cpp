
#include "sapch.h"
#include "GameManager.h"



GameManager::GameManager(Game* game, SDL_Renderer* renderer, SDL_Event* event)
	: m_Event(event), m_Game(game)
{
	//m_TextureManager = std::make_unique<TextureManager>();
	//m_GameplayManager = std::make_unique<GamePlayManager>();
	/*m_ObjectManager = std::make_unique<ObjectManager>(event);*/	
	m_Renderer = std::make_shared<Renderer>(renderer);
	m_StateMachine = std::make_unique<GameStateMachine>(event);
	"game manager const!\n";
}

void GameManager::Render()
{
	m_StateMachine->Render(m_Renderer);

	//m_Renderer->Render(m_ObjectManager->GetPlayer());	
	
	/*switch (m_Game->GameState)
	{
	case Game::State::MainMenu :
		break;
	case Game::State::InGame:
		SDL_ShowCursor(false);
		m_ObjectManager->Render(m_Renderer);
		break;

	}	*/
}

void GameManager::ChangeState(Game::State state)
{
	//m_Game->GameState = state;	
}

void GameManager::Tick()
{
	m_StateMachine->Update();

	/*if (!m_ObjectManager->GetPlayer()->IsAlive())
	{
		m_Game->isRunning = false;
	}

	m_ObjectManager->Tick();*/
}

