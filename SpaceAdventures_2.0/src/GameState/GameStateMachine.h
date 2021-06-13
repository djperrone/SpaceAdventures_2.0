#pragma once
#include "GameState.h"
#include "SDL.h"

class Renderer;

class GameStateMachine
{
public:
	GameStateMachine(SDL_Event* e);
	~GameStateMachine();
	void PushState(GameState* stateToAdd);
	void PopState();
	void Update();
	void Render(std::shared_ptr<Renderer>& renderer);

private:

	std::unordered_map<StateType, std::unique_ptr<GameState>> m_GameStateMap;
	StateType m_CurrentState;
};