#include "sapch.h"
#include "Level.h"
#include "GameManagers/GamePlayManager.h"
#include "MyObjects/Player.h"
#include "DeathScreen.h"
#include "ECS/ProjectileComponent.h"
#include "PauseMenu.h"

class Renderer;

Level::Level(GameStateMachine* stateMachine,InputController* inputController)
	: m_StateMachine(stateMachine), m_InputController(inputController)
{
	std::cout << "level state\n";
	SDL_ShowCursor(false);	
	m_GamePlayManager = std::make_unique<GamePlayManager>(m_InputController);
	m_Player = m_GamePlayManager->GetPlayer();
	
	InitController();
}

Level::~Level()
{
	std::cout << "destryoed level\n";
	SDL_ShowCursor(true);
}

void Level::OnEnter()
{
	SDL_ShowCursor(false);
	IsMouseClicked = true;
	
}

void Level::OnExit()
{
}

void Level::OnUnPause()
{	
	std::cout << "level unpause\n";
	InitController();	
}

void Level::InitController()
{
	m_InputController->Reset();

	m_InputController->BindAxisKeyMapping(SDL_SCANCODE_W, &Player::MoveUp, m_Player);
	m_InputController->BindAxisKeyMapping(SDL_SCANCODE_A, &Player::MoveLeft, m_Player);
	m_InputController->BindAxisKeyMapping(SDL_SCANCODE_S, &Player::MoveDown, m_Player);
	m_InputController->BindAxisKeyMapping(SDL_SCANCODE_D, &Player::MoveRight, m_Player);

	m_InputController->BindAxisKeyMapping(SDL_SCANCODE_ESCAPE, &Player::Pause, m_Player);
	m_InputController->BindActionKeyMapping(SDL_MOUSEBUTTONDOWN, &Player::FireGun, m_Player);
}

void Level::Update()
{	

	if (!m_GamePlayManager->GetPlayer()->IsAlive())
	{
		//m_StateMachine->SetState(new DeathScreen(m_StateMachine, m_Event));
		m_StateMachine->CreateDeathScreen();
		SDL_ShowCursor(true);
		return;
	}
	if (m_GamePlayManager->GetPlayer()->Paused)
	{
		m_StateMachine->PauseGame(m_GamePlayManager->GetPlayer());
		return;
	}
	m_GamePlayManager->Update();
}

void Level::HandleEvents()
{
}

void Level::Render(std::shared_ptr<Renderer>& renderer)
{
	m_GamePlayManager->Render(renderer);
}
