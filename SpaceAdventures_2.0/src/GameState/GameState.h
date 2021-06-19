#pragma once

class Renderer;
class GameStateMachine;

static bool IsMouseClicked = false;


class GameState
{
public:
	GameState() {}
	GameState(GameStateMachine*) {}
	virtual ~GameState() {}
	
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

	virtual void Update() = 0;
	virtual void HandleEvents() = 0;
	virtual void Render(std::shared_ptr<Renderer>& renderer) = 0;
	//virtual GameState* ChangeState() = 0;
	//virtual void OnExit() = 0;
};