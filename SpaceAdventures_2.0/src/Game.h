#pragma once

#include "SDL.h"

class GameManager;

class Game
{
public:	

	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	inline bool IsRunning() { return isRunning; }
	void Render();
	static void Clean();


	static SDL_Event event;
	static bool isRunning;	
	static SDL_Renderer* renderer;
	static SDL_Window* window;
	//static InputHandler* inputHandler;

private:
	int cnt = 0;
	std::unique_ptr<GameManager> m_GameManager;
	
};

