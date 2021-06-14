#include "sapch.h"
#include "Level.h"
#include "GameManagers/GamePlayManager.h"
#include "MyObjects/Player.h"
#include "DeathScreen.h"

class Renderer;

Level::Level(GameStateMachine* stateMachine, SDL_Event* event)
	: m_StateMachine(stateMachine), m_Event(event)
{
	std::cout << "level state\n";
	SDL_ShowCursor(false);
	IsMouseClicked = true;
	m_GamePlayManager = std::make_unique<GamePlayManager>(event);
}

Level::~Level()
{
}

void Level::OnEnter()
{
}

void Level::Update()
{
	if (!m_GamePlayManager->GetPlayer()->IsAlive())
	{
		m_StateMachine->SetState(new DeathScreen(m_StateMachine, m_Event));
		SDL_ShowCursor(true);
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
