#pragma once

#include <SDL.h>
#include "ObjectManager.h"
#include "InputHandler/InputController.h"

class GameState;
class GameStateMachine;
class Renderer;

class InputHandler;
class InputController;

class GameManager
{
public:
	GameManager(SDL_Renderer* renderer, InputController* controller);
	~GameManager();
	void Update();
	void Render();		


private:		
	
	std::shared_ptr<Renderer> m_Renderer;
	std::unique_ptr<GameStateMachine> m_StateMachine;
	std::shared_ptr<InputHandler> m_InputHandler;		
};



