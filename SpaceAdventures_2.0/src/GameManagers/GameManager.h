#pragma once
#include "Renderer.h"
#include "ObjectManager.h"
#include "SDL.h"

class Game;

class GameManager
{

public:

	GameManager(Game* game, SDL_Renderer* renderer, SDL_Event* event);
	void Tick();
	void Render();	

private:
	std::unique_ptr<ObjectManager> m_ObjectManager;
	Game* m_Game;
	std::shared_ptr<Renderer> m_Renderer;
	SDL_Event* m_Event;
};



