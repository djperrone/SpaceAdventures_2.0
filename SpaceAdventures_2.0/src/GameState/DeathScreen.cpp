#include "sapch.h"
#include "DeathScreen.h"
#include "GameManagers/CollisionManager.h"
#include "Dimensions.h"
#include "UI/Button.h"
#include "UI/StaticSprite.h"
#include "GameStateMachine.h"
#include "Level.h"
#include "Game.h"
#include "MainMenu.h"
#include "Renderer.h"

#include "InputHandler/EventListener.h"

DeathScreen::DeathScreen()
{
}

DeathScreen::DeathScreen(GameStateMachine* stateMachine, SDL_Event* event)
	: MainMenu(stateMachine, event)
{
	std::cout << "Death Screen\n";
	//IsMouseClicked = false;
	OnEnter();
}

DeathScreen::~DeathScreen()
{
}

void DeathScreen::OnEnter()
{
	m_CollisionManager = std::make_unique<CollisionManager>();
	Dimensions dimensions;
	std::unique_ptr<StaticSprite> title = std::make_unique<StaticSprite>("assets/DeathScreen.png", 150.0f, 100.0f, 500, 100, 1.0f);
	std::unique_ptr<Button> playButton = std::make_unique<Button>("assets/PlayAgainButton.png", ButtonType::Play, 150.0f, 225.0f, 500, 100, 1);
	std::unique_ptr<Button> mainMenuButton = std::make_unique<Button>("assets/MainMenu.png", ButtonType::MainMenu, 150.0f, 350.0f, 500, 100, 1);
	std::unique_ptr<Button> exitButton = std::make_unique<Button>("assets/ExitButton.png", ButtonType::Exit, 150.0f, 475.0f, 500, 100, 1);

	m_SpriteList.emplace_back(std::move(title));
	m_ButtonList.emplace_back(std::move(playButton));
	m_ButtonList.emplace_back(std::move(mainMenuButton));
	m_ButtonList.emplace_back(std::move(exitButton));

	
}

void DeathScreen::OnExit()
{
}

void DeathScreen::Update()
{
	if (EventListener::Event.type == SDL_MOUSEBUTTONDOWN)
	{
		Vector2i mousePos = Vector2i();
		SDL_GetMouseState(&mousePos.x, &mousePos.y);


		if (!IsMouseClicked)
		{
			IsMouseClicked = true;
			std::cout << "DEATHSCREEN clicked~\n";

			for (const auto& item : m_ButtonList)
			{
				if (m_CollisionManager->IsColliding(item.get(), mousePos))
				{
					switch (item->m_ButtonType)
					{
					case ButtonType::Play: m_StateMachine->CreateNewLevel();
						return;
						break;
					case ButtonType::MainMenu: m_StateMachine->CreateMainMenu();
						return;
					case ButtonType::Exit:
						Game::Clean();
						exit(0);
						break;
					}
				}
			}
		}
	}

	if (m_Event->type == SDL_MOUSEBUTTONUP)
	{
		if (IsMouseClicked)
		{
			std::cout << "UNCLICKED DAETHSCREEN~\n";
			IsMouseClicked = false;
		}
	}
}

void DeathScreen::HandleEvents()
{
}

void DeathScreen::Render(std::shared_ptr<Renderer>& renderer)
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
