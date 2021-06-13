#pragma once
#include "GameState.h"


class ObjectManager;
class Renderer;
union SDL_Event;

class Level : public GameState
{
public:
	
	Level(SDL_Event* event);
	~Level();
	virtual void Update() override;
	virtual void Render(std::shared_ptr<Renderer>& renderer) override;

private:
	std::unique_ptr<ObjectManager> m_ObjectManager;
};