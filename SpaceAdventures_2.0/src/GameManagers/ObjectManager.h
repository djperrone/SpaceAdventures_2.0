#pragma once

#include "Renderer.h"
#include "Dimensions.h"
#include "GameManagers/Spawner.h"
#include "CollisionManager.h"
#include "ProjectileManager.h"
#include "MyObjects/Asteroid.h"
#include "InputHandler/InputController.h"
//class Asteroid;
class Player;
class Projectile;
class Spawner;
class CollissionManager;
class Renderer;
union SDL_Event;
//class KeyboardController;

class ObjectManager
{
public:
	ObjectManager(InputController* inputController);
	void Render(std::shared_ptr<Renderer>& renderer);	
	void Update();
	void CleanList();
	void LoadAllProjectiles();

	bool IsWithinBounds(Character* Character);
	Player* GetPlayer();

private:
	std::unique_ptr<CollisionManager> m_CollisionManager;
	std::shared_ptr<Player> m_Player;	
	//std::unique_ptr<KeyboardController> m_InputController;
	std::unique_ptr<Character> m_MouseController;
	std::unique_ptr<Spawner> m_Spawner;
	Dimensions dimensions;
	std::list<std::shared_ptr<Character>> m_ObjectList;
	std::list<std::shared_ptr<Character>> m_ProjectileList;
	std::list <std::shared_ptr<Ship>> m_ShipList;
	std::list <std::unique_ptr<Asteroid>> m_AsteroidList;

	std::unique_ptr<ProjectileManager> m_ProjectileManager;
	std::unique_ptr<Character> m_ReloadIcon;

	bool isFirst;

};

