#include "sapch.h"
#include "GameManager.h"
#include "GameState/GameStateMachine.h"



GameManager::GameManager(SDL_Renderer* renderer, InputController* controller)
{		

	m_Renderer = std::make_shared<Renderer>(renderer);
	m_StateMachine = std::make_unique<GameStateMachine>(controller);
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

void GameManager::Update()
{	
	
	m_StateMachine->Update();
}



