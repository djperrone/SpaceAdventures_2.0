#include "sapch.h"
#include "GameManager.h"
#include "Renderer.h"
#include "GameState/GameStateMachine.h"


GameManager::GameManager(SDL_Renderer* renderer, SDL_Event* event)
	: m_Event(event)
{	
	
	m_Renderer = std::make_shared<Renderer>(renderer);
	m_InputHandler = std::make_shared<InputHandler>();
	m_StateMachine = std::make_unique<GameStateMachine>(event, m_InputHandler);
	std::cout<<"game manager!\n";
}

void GameManager::Render()
{
	m_StateMachine->Render(m_Renderer);	
}

//void GameManager::SetState(GameState* state)
//{
//	m_StateMachine->SetState(state);
//}

void GameManager::Update()
{
	m_StateMachine->Update();
	//m_InputHandler->Update();
}

