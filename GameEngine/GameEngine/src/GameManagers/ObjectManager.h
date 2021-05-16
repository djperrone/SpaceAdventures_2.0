#pragma once
#include <list>

#include "MyObjects/Player.h"
#include "MyObjects/Asteroid.h"
#include "MyObjects/ShipProjectile.h"
#include "ECS/KeyboardController.h"
#include "GameManagers/Spawner.h"
#include "Renderer.h"
#include "CollisionManager.h"
#include "Dimensions.h"

class GameObject;
class Actor;
class Player;
class Asteroid;

class ObjectManager
{

public:
	ObjectManager(SDL_Event* event);
	void Render(std::shared_ptr<Renderer>& renderer);
	void Tick();
	void Update();
	void CleanList();
	bool IsWithinBounds(Actor* actor);
	Player* GetPlayer() const ;

private:
	std::unique_ptr<CollisionManager> m_CollisionManager;
	std::shared_ptr<Player> m_Player;
	SDL_Event* m_Event;
	std::unique_ptr<KeyboardController> m_InputController;
	std::unique_ptr<Spawner> m_Spawner;
	Dimensions dimensions;
	std::list<std::shared_ptr<Actor>> m_ObjectList;
	//std::list<GameObject*> m_ObjectList_raw;

	

};

