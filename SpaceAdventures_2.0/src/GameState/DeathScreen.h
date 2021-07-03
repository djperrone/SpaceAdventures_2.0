#pragma once
#include "GameState.h"
#include "MainMenu.h"

class DeathScreen : public GameState
{
public:
	DeathScreen();
	DeathScreen(GameStateMachine* stateMachine, InputController* controller);
	~DeathScreen();
	virtual void OnEnter()override;
	virtual void OnExit()override;
	virtual void Update() override;
	virtual void HandleEvents() override;
	virtual void Render(std::shared_ptr<Renderer>& renderer) override;
	virtual void InitController() override;
	bool ButtonEvent();


private:
	std::vector<std::unique_ptr<StaticSprite>> m_SpriteList;
	std::vector<std::unique_ptr<Button>> m_ButtonList;
	std::unique_ptr<CollisionManager> m_CollisionManager;

};
