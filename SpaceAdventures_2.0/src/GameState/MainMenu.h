#pragma once
#include "GameState.h"

class MainMenu : public GameState
{
public:
	MainMenu();
	~MainMenu();
	virtual void Update() override;
	virtual void Render(std::shared_ptr<Renderer>& renderer) override;

private:

};