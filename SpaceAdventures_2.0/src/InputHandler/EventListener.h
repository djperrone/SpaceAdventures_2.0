#pragma once
#include "Game.h"
#include <SDL.h>

class InputHandler;

class EventListener
{
public:
	static SDL_Event Event;
	static bool IsMouseClicked;
	static bool IsMouseRepeating;
	static void PollEvents();
	std::unique_ptr<InputHandler> m_InputHandler;
	
};