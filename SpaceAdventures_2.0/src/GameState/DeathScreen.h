#pragma once
#include "GameState.h"
#include "SDL.h"

class CollisionManager;
class StaticSprite;
class Button;
class GameStateMachine;

class DeathScreen : public GameState
{
public:
	DeathScreen();
	DeathScreen(GameStateMachine* stateMachine, SDL_Event* event);
	~DeathScreen();
	virtual void OnEnter()override;
	virtual void Update() override;
	virtual void HandleEvents() override;
	virtual void Render(std::shared_ptr<Renderer>& renderer) override;

private:
	SDL_Event* m_Event;
	GameStateMachine* m_StateMachine;
	std::unique_ptr<CollisionManager> m_CollisionManager;
	std::vector<std::unique_ptr<StaticSprite>> m_SpriteList;
	std::vector<std::unique_ptr<Button>> m_ButtonList;

	

};
