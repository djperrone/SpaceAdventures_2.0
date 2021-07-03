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

GameStateMachine::GameStateMachine(SDL_Event* e, InputController* inputController)
	: m_Event(e), m_InputController(inputController)
{
	
	
	//m_PlayerController = std::make_unique<PlayerController>();
	//m_UIController = std::make_unique<UIController>();
	//m_InputHandler->SetController(m_UIController.get());
	
	m_CurrentState = std::make_unique<MainMenu>(this, e, inputController);
	std::cout << "initialized gamestate\n";	
	//m_CurrentState = std::make_unique<Level>(e);
	//m_PreviousState = std::make_unique<Level>(e);
}

GameStateMachine::~GameStateMachine()
{
	//m_InputHandler->SetController(new UIController());
}

void GameStateMachine::SetState(GameState* stateToAdd)
{
	GameStateMachine::StateHasChanged = true;
	//m_PreviousState.reset(m_CurrentState.get());
	m_CurrentState.reset(stateToAdd);
	GameStateMachine::StateHasChanged = false;

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
	//EventListener::PollEvents();	
	m_CurrentState->Update();
	//std::cout <<"MAP SIZE " << m_InputHandler->GetInputController()->GetInputMappings().size() << std::endl;;
}

void GameStateMachine::Render(std::shared_ptr<Renderer>& renderer)
{
	m_CurrentState->Render(renderer);
}

void GameStateMachine::CreateNewLevel()
{
	GameStateMachine::StateHasChanged = true;
	//m_InputHandler->SetInputModeToGame();
	//m_InputHandler->SetController(m_PlayerController.get());
	
	m_CurrentState.reset(new Level(this, m_Event, m_InputController));
	GameStateMachine::StateHasChanged = false;

}

void GameStateMachine::CreateMainMenu()
{
	GameStateMachine::StateHasChanged = true;

	//m_InputHandler->SetInputModeToUI();
	//m_InputHandler->SetController(m_UIController.get());

	m_CurrentState.reset(new MainMenu(this, m_Event, m_InputController));//, m_InputHandler->GetInputController()));
	GameStateMachine::StateHasChanged = false;

}

void GameStateMachine::CreateDeathScreen()
{
	//m_InputHandler->SetController(m_UIController.get());
	GameStateMachine::StateHasChanged = true;
	
	m_CurrentState.reset(new DeathScreen(this, m_Event, m_InputController));// , m_InputHandler->GetInputController()));
	GameStateMachine::StateHasChanged = false;
}

void GameStateMachine::PauseGame(Player* player)
{
	//m_InputHandler->SetController(m_UIController.get());
	GameStateMachine::StateHasChanged = true;

	//m_InputHandler->SetInputModeToUI();
	m_PreviousState.reset(new PauseMenu(this, m_Event, m_InputController, player));

	m_CurrentState.swap(m_PreviousState);
	GameStateMachine::StateHasChanged = false;
}

void GameStateMachine::UnPauseGame()
{
	

	m_CurrentState->OnExit();
	m_PreviousState->OnEnter();

	
	m_CurrentState.swap(m_PreviousState);

	m_CurrentState->OnUnPause();


	m_PreviousState.reset();

}