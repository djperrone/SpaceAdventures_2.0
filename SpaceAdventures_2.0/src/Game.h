#pragma once

#include "SDL.h"
#include "GameManagers/GameManager.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();


	static SDL_Event event;
	static bool isRunning;

private:
	SDL_Renderer* renderer;
	int cnt = 0;
	std::unique_ptr<GameManager> m_GameManager;
	SDL_Window* window;
};

