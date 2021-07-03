#include "sapch.h"
#include "PauseMenu.h"
#include "Level.h"
#include "DeathScreen.h"
#include "MyObjects/Player.h"


PauseMenu::PauseMenu()
{
}

PauseMenu::PauseMenu(GameStateMachine* stateMachine, InputController* controller, Player* player)
	: m_Player(player)
{
	m_InputController = controller;
	m_StateMachine = stateMachine;
	SDL_ShowCursor(true);
	OnEnter();
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::OnEnter()
{
	m_CollisionManager = std::make_unique<CollisionManager>();
	Dimensions dimensions;
	std::unique_ptr<StaticSprite> title = std::make_unique<StaticSprite>("assets/title.png", -100.0f, 100.0f, 1000, 100, 1.0f);
	std::unique_ptr<Button> playButton = std::make_unique<Button>("assets/PlayButton.png", ButtonType::Play, 150.0f, 225.0f, 500, 100, 1);
	std::unique_ptr<Button> mainMenuButton = std::make_unique<Button>("assets/MainMenu.png", ButtonType::MainMenu, 150.0f, 350.0f, 500, 100, 1);
	std::unique_ptr<Button> exitButton = std::make_unique<Button>("assets/ExitButton.png", ButtonType::Exit, 150.0f, 475.0f, 500, 100, 1);
	//m_InputController->Reset();
	m_SpriteList.emplace_back(std::move(title));
	m_ButtonList.emplace_back(std::move(playButton));
	m_ButtonList.emplace_back(std::move(mainMenuButton));
	m_ButtonList.emplace_back(std::move(exitButton));

	//-----------------------------------------------------
	m_InputController->Reset();

	InitController();	
}

void PauseMenu::Update()
{
	/*for (const auto& item : m_SpriteList)
	{
		item->Update();
	}*/
		
}

void PauseMenu::InitController()
{
	m_InputController->BindActionKeyMapping(SDL_MOUSEBUTTONDOWN, &PauseMenu::ButtonEvent, this);
}

bool PauseMenu::ButtonEvent()
{
	Vector2i mousePos = Vector2i();
	SDL_GetMouseState(&mousePos.x, &mousePos.y);		

	for (const auto& item : m_ButtonList)
	{
		if (m_CollisionManager->IsColliding(item.get(), mousePos))
		{
			switch (item->m_ButtonType)
			{
			case ButtonType::Play: IsMouseClicked = true; m_StateMachine->UnPauseGame();
				return true;

			case ButtonType::MainMenu: m_StateMachine->CreateMainMenu();
				return true;

			case ButtonType::Exit:
				m_StateMachine->CreateMainMenu();
				return true;
			}
		}
	}
	
	return false;
}

void PauseMenu::HandleEvents()
{

}

void PauseMenu::OnExit()
{
	IsMouseClicked = true;
	m_Player->Paused = false;
}

void PauseMenu::Render(std::shared_ptr<Renderer>& renderer)
{
	

	for (const auto& item : m_SpriteList)
	{
		renderer->Render(item.get());
	}
	for (const auto& item : m_ButtonList)
	{
		renderer->Render(item.get());
	}
}
