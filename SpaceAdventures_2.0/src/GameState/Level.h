#pragma once
#include "GameState.h"
#include "GameStateMachine.h"
#include "InputHandler/InputController.h"
#include "MyObjects/Player.h"


class GamePlayManager;;
class Renderer;
union SDL_Event;

class Level : public GameState
{
public:
	
	Level(GameStateMachine* stateMachine, SDL_Event* event, InputController* inputController);
	~Level();
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnUnPause() override;
	virtual void Update() override;
	virtual void HandleEvents() override;
	virtual void Render(std::shared_ptr<Renderer>& renderer) override;
	virtual void InitController() override;
	//void InitController(Player* player);

private:
	//std::unique_ptr<ObjectManager> m_ObjectManager;
	std::unique_ptr<GamePlayManager> m_GamePlayManager;
	SDL_Event* m_Event;
	GameStateMachine* m_StateMachine;
	InputController* m_InputController;
	Player* m_Player;
};