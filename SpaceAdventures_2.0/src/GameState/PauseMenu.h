#pragma once
#include "GameState.h"
#include "SDL.h"
#include "Dimensions.h"

class CollisionManager;
class StaticSprite;
class Button;
class Renderer;
class Player;

class PauseMenu : public GameState
{
public:
	//PauseMenu(SDL_Event* event);
	PauseMenu(GameStateMachine* stateMachine, SDL_Event* event, Player* player);
	~PauseMenu();
	virtual void OnEnter() override;
	virtual void Update() override;
	virtual void HandleEvents() override;
	virtual void OnExit() override;

	virtual void Render(std::shared_ptr<Renderer>& renderer) override;

private:
	std::vector<std::unique_ptr<StaticSprite>> m_SpriteList;
	std::vector<std::unique_ptr<Button>> m_ButtonList;
	std::unique_ptr<CollisionManager> m_CollisionManager;
	SDL_Event* m_Event;
	GameStateMachine* m_StateMachine;
	Player* m_Player;
	//bool clicked = true;
};