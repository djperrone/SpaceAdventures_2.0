#pragma once

#include "SDL.h"
#include "InputHandler/EventListener.h"
#include "InputHandler/InputHandler.h"

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

	std::unique_ptr<GameManager> m_GameManager;
private:
	std::unique_ptr<InputHandler> m_InputHandler;
	int cnt = 0;
	
};

