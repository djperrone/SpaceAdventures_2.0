#pragma once
#include <memory>
#include <vector>
#include <list>

#include "MyObjects/Player.h"
#include "MyObjects/Asteroid.h"
#include "ECS/KeyboardController.h"
#include "GameManagers/Spawner.h"
#include "Renderer.h"

//class Player;
class GameObject;
class Actor;

class ObjectManager
{

public:
	ObjectManager(SDL_Event* event);
	void Render(std::shared_ptr<Renderer>& renderer);
	void Tick();
	void Update();
	Player* GetPlayer() const ;

private:
	std::shared_ptr<Player> m_Player;
	SDL_Event* m_Event;
	std::unique_ptr<KeyboardController> m_InputController;
	std::unique_ptr<Spawner> m_Spawner;

	std::list<std::shared_ptr<Actor>> m_ObjectList;
	//std::list<GameObject*> m_ObjectList_raw;

	

};

