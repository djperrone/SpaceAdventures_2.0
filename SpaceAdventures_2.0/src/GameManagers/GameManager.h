#pragma once

#include <SDL.h>
#include "ObjectManager.h"
#include "Game.h"
//#include "GameState/GameStateMachine.h"
//#include "InputHandler/InputHandler.h"
//#include "InputHandler/InputListener.h"

class GameState;
class GameStateMachine;
class Renderer;
union SDL_event;

class InputHandler;




class GameManager
{
public:
	GameManager(SDL_Renderer* renderer, SDL_Event* event);
	~GameManager();
	void Update();
	void Render();	
	//static SDL_Event Event;
	void PollEvents();
	//void SetState(GameState* state);
	//static InputListener* s_InputListener;
private:		
	
	std::shared_ptr<Renderer> m_Renderer;
	SDL_Event* m_Event;
	std::unique_ptr<GameStateMachine> m_StateMachine;
	std::shared_ptr<InputHandler> m_InputHandler;	
};



