#pragma once

class Renderer;
class GameState;
class Player;
#include "SDL.h"

class GameStateMachine
{
public:
	GameStateMachine(SDL_Event* e);
	~GameStateMachine();
	void SetState(GameState* newState);
	void AddLevelState();
	
	GameState* GetState();
	void Update();
	void Render(std::shared_ptr<Renderer>& renderer);

	void CreateNewLevel();
	void CreateMainMenu();
	void CreateDeathScreen();
	void PauseGame(Player* player);
	void UnPauseGame();


	void  Print() { std::cout << "hello ther~!\n"; }

private:
	std::unique_ptr<GameState> m_CurrentState;
	std::unique_ptr<GameState> m_PreviousState;
	SDL_Event* m_Event;
	//std::unordered_map<StateType, std::unique_ptr<GameState>> m_GameStateMap;
	/*StateType m_CurrentState;*/
};