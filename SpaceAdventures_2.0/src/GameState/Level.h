#pragma once
#include "GameState.h"
#include "GameStateMachine.h"


class GamePlayManager;;
class Renderer;
union SDL_Event;

class Level : public GameState
{
public:
	
	Level(GameStateMachine* stateMachine, SDL_Event* event);
	~Level();
	virtual void OnEnter() override;
	virtual void OnUnPause();
	virtual void Update() override;
	virtual void HandleEvents() override;
	virtual void Render(std::shared_ptr<Renderer>& renderer) override;

private:
	//std::unique_ptr<ObjectManager> m_ObjectManager;
	std::unique_ptr<GamePlayManager> m_GamePlayManager;
	SDL_Event* m_Event;
	GameStateMachine* m_StateMachine;
};