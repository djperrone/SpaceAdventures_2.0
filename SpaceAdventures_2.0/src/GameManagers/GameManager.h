#pragma once

#include "ObjectManager.h"
#include "GameState/GameStateMachine.h"

class GameState;
class GameStateMachine;
class Renderer;
union SDL_event;

class GameManager
{
public:
	GameManager(SDL_Renderer* renderer, SDL_Event* event);
	void Update();
	void Render();	
	//void SetState(GameState* state);

private:		
	std::shared_ptr<Renderer> m_Renderer;
	SDL_Event* m_Event;
	std::unique_ptr<GameStateMachine> m_StateMachine;
};



