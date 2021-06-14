#include "sapch.h"
#include "game.h"

void GameLoop();


int main(int argc, char** argv)	
{			
	GameLoop();	
	return 0;
}

void GameLoop()
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Game* game = new Game();
	game->Init("Asteroid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->IsRunning())
	{
		frameStart = SDL_GetTicks();
		//sound.Play();
		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->Clean();
	delete game;
}
