#pragma once

#include "SDL.h"

class GameManager;

class Game
{
public:

	enum class State
	{
		None = 0,
		MainMenu,
		InGame,
		PauseScreen,
		DeathScreen
	};

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	inline bool running() { return isRunning; }
	void render();
	void clean();


	static SDL_Event event;
	static bool isRunning;
	State GameState;

private:
	SDL_Renderer* renderer;
	int cnt = 0;
	std::unique_ptr<GameManager> m_GameManager;
	SDL_Window* window;
	
};

