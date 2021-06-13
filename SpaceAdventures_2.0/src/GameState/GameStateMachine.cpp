#include "sapch.h"
#include "GameStateMachine.h"
#include "MainMenu.h"
#include "Level.h"
GameStateMachine::GameStateMachine(SDL_Event* e)
{
	std::cout << "initialized gamestate\n";
	m_CurrentState = StateType::MainMenu;
	m_GameStateMap[m_CurrentState] = std::make_unique<Level>(e);
}

GameStateMachine::~GameStateMachine()
{
}

void GameStateMachine::PushState(GameState* stateToAdd)
{
	if (m_GameStateMap.find(stateToAdd->GetStateType()) != m_GameStateMap.end())
	{
		std::cout << "Error already in state\n";
	}
	else
	{
		
		m_GameStateMap[stateToAdd->GetStateType()].reset(stateToAdd);
		m_GameStateMap.erase(m_CurrentState);
		m_CurrentState = stateToAdd->GetStateType();
	}
}

void GameStateMachine::PopState()
{
}

void GameStateMachine::Update()
{
	m_GameStateMap[m_CurrentState]->Update();
}

void GameStateMachine::Render(std::shared_ptr<Renderer>& renderer)
{
	m_GameStateMap[m_CurrentState]->Render(renderer);

}
