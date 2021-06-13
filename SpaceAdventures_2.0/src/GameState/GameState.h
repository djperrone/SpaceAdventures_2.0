#pragma once

class Renderer;

class GameState
{
public:
	GameState() {}
	virtual ~GameState() {}
	
	//virtual void OnEnter() = 0;
	virtual void Update() = 0;
	virtual void Render(std::shared_ptr<Renderer>& renderer) = 0;
	//virtual void OnExit() = 0;
};