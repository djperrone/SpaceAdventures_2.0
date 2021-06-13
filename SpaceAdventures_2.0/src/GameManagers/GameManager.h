#pragma once
#include "Renderer.h"
#include "ObjectManager.h"
#include "SDL.h"
#include "Game.h"

#include "GameState/GameStateMachine.h"

class GameManager
{

public:

	GameManager(Game* game, SDL_Renderer* renderer, SDL_Event* event);
	void Tick();
	void Render();	
	void ChangeState(Game::State state);

private:
	
	Game* m_Game;
	std::shared_ptr<Renderer> m_Renderer;
	SDL_Event* m_Event;

	std::unique_ptr<GameStateMachine> m_StateMachine;
};



