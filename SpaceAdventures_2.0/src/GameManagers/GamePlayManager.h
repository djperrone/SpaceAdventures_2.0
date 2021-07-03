#pragma once
#include "SDL.h"
#include "InputHandler/InputController.h"

class ObjectManager;
class Renderer;
class Player;

class GamePlayManager
{
public:
	GamePlayManager();
	GamePlayManager(InputController* inputController);
	~GamePlayManager();
	void Update();
	void HandleEvents();
	void Render(std::shared_ptr<Renderer>& renderer);
	Player* GetPlayer();

private:
	std::unique_ptr<ObjectManager> m_ObjectManager;
};