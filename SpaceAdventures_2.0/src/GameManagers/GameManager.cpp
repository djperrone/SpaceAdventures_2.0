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

GameManager::GameManager(SDL_Renderer* renderer, SDL_Event* event, InputController* controller)
	: m_Event(event)
{		

	m_Renderer = std::make_shared<Renderer>(renderer);
	m_StateMachine = std::make_unique<GameStateMachine>(event, controller);
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

	
}

void GameManager::Update()
{	
	
	m_StateMachine->Update();
}

InputHandler* GameManager::GetInputHandler()
{
	return m_InputHandler.get();
}

