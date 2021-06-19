#pragma once
#include "GameState.h"
#include "SDL.h"
#include "MainMenu.h"

class DeathScreen : public MainMenu
{
public:
	DeathScreen();
	DeathScreen(GameStateMachine* stateMachine, SDL_Event* event);
	~DeathScreen();
	virtual void OnEnter()override;
	virtual void OnExit()override;
	virtual void Update() override;
	virtual void HandleEvents() override;
	virtual void Render(std::shared_ptr<Renderer>& renderer) override;

private:
	

};
