#include "sapch.h"
#include "Game.h"
#include "GameManagers/GameManager.h"


SDL_Event Game::event;
SDL_Window* Game::window;
SDL_Renderer* Game::renderer;

bool Game::isRunning = false;

Game::Game()
{
	
}

Game::~Game()
{}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized!..." << std::endl;

		Game::window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (Game::window)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(Game::window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0,255);
			std::cout << "Renderer Created!" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}	
	m_GameManager = std::make_unique<GameManager>(Game::renderer, &event);	
}

void Game::HandleEvents()
{	
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update()
{
	cnt++;	
	m_GameManager->Update();	
}

void Game::Render()
{
	SDL_RenderClear(renderer);	
	m_GameManager->Render();
	SDL_RenderPresent(renderer);	
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}