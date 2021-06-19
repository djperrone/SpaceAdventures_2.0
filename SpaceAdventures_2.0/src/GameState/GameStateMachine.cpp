#include "sapch.h"
#include "SDL.h"
#include "GameStateMachine.h"
#include "GameState.h"
#include "MainMenu.h"
#include "Level.h"
#include "DeathScreen.h"
#include "PauseMenu.h"

GameStateMachine::GameStateMachine(SDL_Event* e, std::shared_ptr<InputHandler> inputHandler)
	: m_Event(e), m_InputHandler(inputHandler)
{
	std::cout << "initialized gamestate\n";	
	m_InputHandler->SetInputModeToUI();
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

void GameStateMachine::PauseGame(Player* player)
{	
	//m_InputHandler->SetInputModeToUI();
	m_PreviousState.reset(new PauseMenu(this,m_Event, player));
	
	m_CurrentState.swap(m_PreviousState);
}

void GameStateMachine::UnPauseGame()
{
	m_CurrentState->OnExit();
	m_PreviousState->OnEnter();
	IsMouseClicked = true;
	//m_InputHandler->SetInputModeToGame();
	m_CurrentState.swap(m_PreviousState);	
	m_PreviousState.reset();
}

GameState* GameStateMachine::GetState()
{
	return m_CurrentState.get();
}

void GameStateMachine::Update()
{
	m_InputHandler->Update();
	m_CurrentState->Update();
	std::cout <<"MAP SIZE " << m_InputHandler->GetInputController()->GetInputMappings().size() << std::endl;;
}

void GameStateMachine::Render(std::shared_ptr<Renderer>& renderer)
{
	m_CurrentState->Render(renderer);
}

void GameStateMachine::CreateNewLevel()
{
	m_InputHandler->SetInputModeToGame();
	m_CurrentState.reset(new Level(this, m_Event, m_InputHandler->GetInputController()));
}

void GameStateMachine::CreateMainMenu()
{
	m_InputHandler->SetInputModeToUI();
	m_CurrentState.reset(new MainMenu(this, m_Event));//, m_InputHandler->GetInputController()));
}

void GameStateMachine::CreateDeathScreen()
{
	m_InputHandler->SetInputModeToUI();
	m_CurrentState.reset(new DeathScreen(this, m_Event));// , m_InputHandler->GetInputController()));
}
