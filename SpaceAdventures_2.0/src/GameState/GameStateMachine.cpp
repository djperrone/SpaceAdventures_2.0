#include "sapch.h"
#include "SDL.h"
#include "GameStateMachine.h"
#include "GameState.h"
#include "MainMenu.h"
#include "Level.h"
#include "DeathScreen.h"
#include "PauseMenu.h"
#include "InputHandler/EventListener.h"

bool GameStateMachine::StateHasChanged = false;

GameStateMachine::GameStateMachine(InputController* inputController)
	: m_InputController(inputController)
{	
	m_CurrentState = std::make_unique<MainMenu>(this, inputController);
	std::cout << "initialized gamestate\n";		
}

GameStateMachine::~GameStateMachine()
{
	
}

void GameStateMachine::SetState(GameState* stateToAdd)
{
	m_CurrentState.reset(stateToAdd);
}


GameState* GameStateMachine::GetState()
{
	return m_CurrentState.get();
}

void GameStateMachine::Update()
{	
	m_CurrentState->Update();	
}

void GameStateMachine::Render(std::shared_ptr<Renderer>& renderer)
{
	m_CurrentState->Render(renderer);
}

void GameStateMachine::CreateNewLevel()
{	
	m_CurrentState.reset(new Level(this, m_InputController));
}

void GameStateMachine::CreateMainMenu()
{	
	m_CurrentState.reset(new MainMenu(this, m_InputController));
}

void GameStateMachine::CreateDeathScreen()
{	
	m_CurrentState.reset(new DeathScreen(this, m_InputController));	
}

void GameStateMachine::PauseGame(Player* player)
{		
	m_CurrentState->OnPause();
	m_PreviousState.reset(new PauseMenu(this, m_InputController, player));
	m_CurrentState.swap(m_PreviousState);	
}

void GameStateMachine::UnPauseGame()
{
	m_CurrentState->OnExit();
	m_PreviousState->OnEnter();	
	m_CurrentState.swap(m_PreviousState);
	m_CurrentState->OnUnPause();
	m_PreviousState.reset();
}