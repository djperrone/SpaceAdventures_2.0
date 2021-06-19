#pragma once
#include "GameState.h"
#include "GameStateMachine.h"
#include "SDL.h"
#include "Dimensions.h"
#include "GameManagers/CollisionManager.h"
#include "UI/StaticSprite.h"
#include "UI/Button.h"
#include "Renderer.h"

class MainMenu : public GameState
{
public:
	MainMenu();
	MainMenu(GameStateMachine* stateMachine, SDL_Event* event);
	~MainMenu();
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void Update() override;
	virtual void HandleEvents() override;

	virtual void Render(std::shared_ptr<Renderer>& renderer) override;

protected:
	std::vector<std::unique_ptr<StaticSprite>> m_SpriteList;
	std::vector<std::unique_ptr<Button>> m_ButtonList;
	std::unique_ptr<CollisionManager> m_CollisionManager;
	SDL_Event* m_Event;
	GameStateMachine* m_StateMachine;
	//bool clicked = true;
};