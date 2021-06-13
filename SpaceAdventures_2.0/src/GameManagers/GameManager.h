#pragma once
#include "Renderer.h"
#include "ObjectManager.h"
#include "SDL.h"
#include "Game.h"
#include "GameState/GameStateMachine.h"

class Gamestate;
class GameStateMachine;

class GameManager
{
public:
	GameManager(SDL_Renderer* renderer, SDL_Event* event);
	void Update();
	void Render();	
	void SetState(GameState* state);

private:		
	std::shared_ptr<Renderer> m_Renderer;
	SDL_Event* m_Event;
	std::unique_ptr<GameStateMachine> m_StateMachine;
};



