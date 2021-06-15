#include "sapch.h"
#include "PauseMenu.h"
#include "UI/StaticSprite.h"
#include "UI/Button.h"
#include "Renderer.h"
#include "GameManagers/CollisionManager.h"
#include "GameStateMachine.h"
#include "Level.h"
#include "DeathScreen.h"
#include "Game.h"
#include "MyObjects/Player.h"

//PauseMenu::PauseMenu(SDL_Event* event)
//	: m_Event(event)
//{
//	OnEnter();
//}

PauseMenu::PauseMenu(GameStateMachine* stateMachine, SDL_Event* event, Player* player)
	:m_StateMachine(stateMachine), m_Event(event), m_Player(player)
{
	IsMouseClicked = false;
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
	std::unique_ptr<Button> playButton = std::make_unique<Button>("assets/ResumeButton.png",ButtonType::Play, 150.0f, 225.0f, 500, 100, 1);
	std::unique_ptr<Button> exitButton = std::make_unique<Button>("assets/ExitButton.png", ButtonType::Exit, 150.0f, 350.0f, 500,100,1);

	m_SpriteList.emplace_back(std::move(title));
	m_ButtonList.emplace_back(std::move(playButton));
	m_ButtonList.emplace_back(std::move(exitButton));
}

void PauseMenu::Update()
{
	/*for (const auto& item : m_SpriteList)
	{
		item->Update();
	}*/
	

	if (m_Event->type == SDL_MOUSEBUTTONDOWN)
	{
		Vector2i mousePos = Vector2i();
		SDL_GetMouseState(&mousePos.x, &mousePos.y);
		
		if (!IsMouseClicked)
		{
			IsMouseClicked = true;
			std::cout << "clickedPauseMenu~\n";

			for (const auto& item : m_ButtonList)
			{
				if (m_CollisionManager->IsColliding(item.get(), mousePos))
				{
					switch (item->m_ButtonType)
					{
					case ButtonType::Play:IsMouseClicked = true; m_StateMachine->UnPauseGame();
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
			std::cout << "unclick pause menu~\n";
			IsMouseClicked = false;
		}
	}	
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
