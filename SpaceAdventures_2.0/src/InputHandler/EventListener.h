#pragma once
#include "Game.h"
#include <SDL.h>
#include "GameState/GameStateMachine.h"

class GameManager;
class InputHandler;

class EventListener
{
public:
	static SDL_Event Event;
	static bool IsMouseClicked;
	static bool IsMouseRepeating;
	static void PollEvents();	
};