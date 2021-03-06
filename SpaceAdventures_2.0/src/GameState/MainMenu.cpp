#include "sapch.h"
#include "MainMenu.h"

#include "Level.h"
#include "DeathScreen.h"
#include "Game.h"

#include "InputHandler/EventListener.h"

//MainMenu::MainMenu(SDL_Event* event)
//	: m_Event(event)
//{
//	OnEnter();
//}

MainMenu::MainMenu()
{
}

MainMenu::MainMenu(GameStateMachine* stateMachine, InputController* controller)
	:m_StateMachine(stateMachine), m_InputController(controller)
{

	OnEnter();
}

MainMenu::~MainMenu()
{
}

void MainMenu::OnEnter()
{
	m_CollisionManager = std::make_unique<CollisionManager>();
	Dimensions dimensions;
	std::unique_ptr<StaticSprite> title = std::make_unique<StaticSprite>("assets/title.png", -100.0f, 100.0f, 1000, 100, 1.0f);
	std::unique_ptr<Button> playButton = std::make_unique<Button>("assets/PlayButton.png",ButtonType::Play, 150.0f, 225.0f, 500, 100, 1);
	std::unique_ptr<Button> exitButton = std::make_unique<Button>("assets/ExitButton.png", ButtonType::Exit, 150.0f, 350.0f, 500,100,1);

	m_SpriteList.emplace_back(std::move(title));
	m_ButtonList.emplace_back(std::move(playButton));
	m_ButtonList.emplace_back(std::move(exitButton));

	m_InputController->Reset();
	std::cout << "main menu\n";
	InitController();
}

void MainMenu::OnExit()
{
}

void MainMenu::InitController()
{
	m_InputController->BindActionMapping(SDL_BUTTON_LEFT, SDL_MOUSEBUTTONDOWN, &MainMenu::ButtonEvent, this);
}

bool MainMenu::ButtonEvent()
{
	
	Vector2i mousePos = Vector2i();
	SDL_GetMouseState(&mousePos.x, &mousePos.y);

	for (const auto& item : m_ButtonList)
	{
		if (m_CollisionManager->IsColliding(item.get(), mousePos))
		{
			switch (item->m_ButtonType)
			{
			case ButtonType::Play: m_StateMachine->CreateNewLevel();
				return true;
			case ButtonType::Exit:
				Game::Clean();
				exit(0);
				return true;
			}
		}
	}

	return false;
}

void MainMenu::Update()
{

}

void MainMenu::HandleEvents()
{
}

void MainMenu::Render(std::shared_ptr<Renderer>& renderer)
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
