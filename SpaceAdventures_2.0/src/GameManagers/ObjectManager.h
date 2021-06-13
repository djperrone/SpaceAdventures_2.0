#pragma once

#include "Renderer.h"
#include "Dimensions.h"
#include "GameManagers/Spawner.h"
#include "CollisionManager.h"
#include "ProjectileManager.h"

#include "ECS/KeyboardController.h"
#include "MyObjects/Player.h"
#include "MyObjects/Asteroid.h"
#include "ObjectTemplates/Projectile.h"
#include "ObjectTemplates/ReloadIcon.h"
#include "ObjectTemplates/MouseCursor.h"

class ObjectManager
{
public:
	ObjectManager(SDL_Event* event);
	void Render(std::shared_ptr<Renderer>& renderer);
	void Tick();
	void Update();
	void CleanList();
	void LoadAllProjectiles();

	bool IsWithinBounds(Actor* actor);
	Player* GetPlayer() const ;

private:
	std::unique_ptr<CollisionManager> m_CollisionManager;
	std::shared_ptr<Player> m_Player;
	SDL_Event* m_Event;
	std::unique_ptr<KeyboardController> m_InputController;
	std::unique_ptr<MouseCursor> m_MouseController;
	std::unique_ptr<Spawner> m_Spawner;
	Dimensions dimensions;
	std::list<std::shared_ptr<Actor>> m_ObjectList;
	std::list<std::shared_ptr<Actor>> m_ProjectileList;
	std::list <std::shared_ptr<Ship>> m_ShipList;
	std::list <std::unique_ptr<Asteroid>> m_AsteroidList;

	std::unique_ptr<ProjectileManager> m_ProjectileManager;
	std::unique_ptr<ReloadIcon> m_ReloadIcon;

};

