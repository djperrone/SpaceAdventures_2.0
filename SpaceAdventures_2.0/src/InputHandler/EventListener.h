#pragma once

#include <SDL.h>

class GameManager;
class InputHandler;

class EventListener
{
public:
	static SDL_Event Event;
	static bool IsMouseClicked;
	static bool IsMouseRepeating;
};