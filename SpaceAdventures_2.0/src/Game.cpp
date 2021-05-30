#include "Game.h"

#include <string>
#include <iostream>



//SDL_Renderer* Game::renderer = nullptr;

SDL_Event Game::event;

bool Game::isRunning = false;



Game::Game()
{
	
}

Game::~Game()
{}



void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0,255);
			std::cout << "Renderer Created!" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	// parameters are filepath to picture, xloc, yloc, scale	
	
	//player = new Player("D:/Dev/Asteroid_old/GameEngine/GameEngine/assets/ship.png", 0, 0,4);
	
	m_GameManager = std::make_unique<GameManager>(this,renderer, &event);
	
	

	

}

//COLLISION GROUPS


void Game::handleEvents()
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

void Game::update()
{
	cnt++;
	//std::cout << cnt << std::endl;
	//player->Update();
	//asteroid->Update();
	m_GameManager->Tick();
	
}



void Game::render()
{
	SDL_RenderClear(renderer);
	// order of render groupings
	//render map tiles, characters

	// top is background, bottom goes to foreground
	
	//player->Render();
	//gameManager->asteroidVec[0]->Render();
	/*for (auto a : gameManager->asteroidVec)
	{
		a->Render();
	}*/


	//steroid->Render();
	m_GameManager->Render();

	SDL_RenderPresent(renderer);	
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}