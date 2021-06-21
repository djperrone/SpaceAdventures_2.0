#include "sapch.h"
#include "GameManager.h"
#include "Renderer.h"
#include "GameState/GameStateMachine.h"
#include "Game.h"


//InputListener* listener = InputListener::GetInputListener();
//InputListener::GetEvent();
//InputListener* GameManager::s_InputListener;
//SDL_Event EventListener::Event;
//bool EventListener::IsMouseClicked;

GameManager::GameManager(SDL_Renderer* renderer, SDL_Event* event)
	: m_Event(event)
{	
	//InputListener::CreateInputListener();

	m_Renderer = std::make_shared<Renderer>(renderer);
	m_InputHandler = std::make_shared<InputHandler>();
	m_StateMachine = std::make_unique<GameStateMachine>(event, m_InputHandler);
	std::cout<<"game manager!\n";
}

GameManager::~GameManager()
{
	//delete s_InputListener;
}

void GameManager::Render()
{
	m_StateMachine->Render(m_Renderer);	
}

void GameManager::PollEvents()
{
	//while (SDL_PollEvent(&EventListener::Event))
	//{
	//	switch (EventListener::Event.type)
	//	{
	//	case SDL_QUIT:
	//		Game::isRunning = false;
	//		break;
	//	/*case SDL_MOUSEBUTTONDOWN: EventListener::IsMouseClicked = true;
	//		break;
	//	case SDL_MOUSEBUTTONUP:
	//		EventListener::IsMouseClicked = false;
	//		break;*/
	//	default:
	//		break;
	//	}
	//}

	
}

//void GameManager::SetState(GameState* state)
//{
//	m_StateMachine->SetState(state);
//}

void GameManager::Update()
{
	//EventListener::PollEvents();
	//s_InputListener->PollEvents();
	m_StateMachine->Update();
	//m_InputHandler->Update();
}

