#pragma once
#include "Renderer.h"

enum class StateType
{
	None = 0,
	MainMenu,
	InGame,
	DeathScreen
};

#define STATE_CLASS_TYPE(type) static StateType GetStaticType() {return StateType::##type;}\
								virtual StateType GetStateType() const override {return GetStaticType();}



class GameState
{
public:
	GameState() {}
	virtual ~GameState() {}
	virtual StateType GetStateType() const { return StateType::None; }

	//virtual void OnEnter() = 0;
	virtual void Update() = 0;
	virtual void Render(std::shared_ptr<Renderer>& renderer) = 0;
	//virtual void OnExit() = 0;
};