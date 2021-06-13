#include "sapch.h"
#include "GameStateMachine.h"
#include "GameState.h"
#include "MainMenu.h"
#include "Level.h"

GameStateMachine::GameStateMachine(SDL_Event* e)
{
	std::cout << "initialized gamestate\n";	
	m_CurrentState = std::make_unique<Level>(e);
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
