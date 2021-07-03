#pragma once
#include "GameState.h"
#include "Dimensions.h"
#include "MainMenu.h"
class Player;

class PauseMenu : public GameState
{
public:
	PauseMenu();
	PauseMenu(GameStateMachine* stateMachine, InputController* controller, Player* player);
	~PauseMenu();
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void Update() override;
	virtual void HandleEvents() override;
	virtual void InitController() override;
	bool ButtonEvent();
	virtual void Render(std::shared_ptr<Renderer>& renderer) override;

private:

	Player* m_Player;	
	std::vector<std::unique_ptr<StaticSprite>> m_SpriteList;
	std::vector<std::unique_ptr<Button>> m_ButtonList;
	std::unique_ptr<CollisionManager> m_CollisionManager;
};