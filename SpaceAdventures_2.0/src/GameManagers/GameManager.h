#pragma once
#include <memory>


#include "Renderer.h"
#include "ObjectManager.h"
#include "SDL.h"

//class GameObject;
//class ObjectManager;
//class Player;
//class TextureManager;

//class AsteroidModel;
class Game;

class GameManager
{
private:

	//std::unique_ptr<TextureManager> m_TextureManager;
	//std::unique_ptr<GamePlayManager>  m_GameplayManager;
	std::unique_ptr<ObjectManager> m_ObjectManager;
	Game* m_Game;
	std::shared_ptr<Renderer> m_Renderer;
	SDL_Event* m_Event;

public:

	GameManager(Game* game, SDL_Renderer* renderer, SDL_Event* event);
	void Tick();
	void Render();

	
};


