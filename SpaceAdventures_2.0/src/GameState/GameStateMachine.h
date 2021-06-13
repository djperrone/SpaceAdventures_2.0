#pragma once

class Renderer;
class GameState;
union SDL_Event;

class GameStateMachine
{
public:
	GameStateMachine(SDL_Event* e);
	~GameStateMachine();
	void SetState(GameState* newState);	
	GameState* GetState();
	void Update();
	void Render(std::shared_ptr<Renderer>& renderer);

private:
	std::unique_ptr<GameState> m_CurrentState;
	//std::unordered_map<StateType, std::unique_ptr<GameState>> m_GameStateMap;
	/*StateType m_CurrentState;*/
};