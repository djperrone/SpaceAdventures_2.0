#include "sapch.h"
#include "SDL.h"
#include "GameStateMachine.h"
#include "GameState.h"
#include "MainMenu.h"
#include "Level.h"
#include "DeathScreen.h"

GameStateMachine::GameStateMachine(SDL_Event* e)
	: m_Event(e)
{
	std::cout << "initialized gamestate\n";	
	m_CurrentState = std::make_unique<MainMenu>(this, e);
	//m_CurrentState = std::make_unique<Level>(e);
	//m_PreviousState = std::make_unique<Level>(e);
}

GameStateMachine::~GameStateMachine()
{
}

void GameStateMachine::SetState(GameState* stateToAdd)
{
	//m_PreviousState.reset(m_CurrentState.get());
	m_CurrentState.reset(stateToAdd);
	//m_CurrentState->Update();
}

void GameStateMachine::AddLevelState()
{
	std::cout << "Add level state\n";
	//m_PreviousState.reset(m_CurrentState.get());
	//m_CurrentState.reset(new Level(m_Event));
	//m_CurrentState.reset();
	//m_CurrentState->Update();
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
