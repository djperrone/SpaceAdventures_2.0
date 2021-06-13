#pragma once
#include "GameState.h"
#include "Renderer.h"

class ObjectManager;

class Level : public GameState
{
public:
	STATE_CLASS_TYPE(InGame);
	Level(SDL_Event* event);
	~Level();
	virtual void Update() override;
	virtual void Render(std::shared_ptr<Renderer>& renderer) override;

private:
	std::unique_ptr<ObjectManager> m_ObjectManager;
};