#include "sapch.h"
#include "game.h"


Game* game = nullptr;


void GameLoop(Game* game);


int main(int argc, char** argv)	
{	
	
	game = new Game();
	GameLoop(game);
	//game = new Game();
	//GameLoop(game);
	
	return 0;
}

void GameLoop(Game* game)
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Asteroid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks();
		//sound.Play();
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
}









//#include "SDL.h"
//
//int main(int argc, char** argv)
//{
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Window* window = SDL_CreateWindow("Asteroid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
//	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,0);
//
//	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//
//	SDL_RenderClear(renderer);
//
//	SDL_RenderPresent(renderer);
//
//	SDL_Delay(5000);
//
//
//
//
//	return 0;
//}