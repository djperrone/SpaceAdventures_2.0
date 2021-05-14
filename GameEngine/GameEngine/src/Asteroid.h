#pragma once
#include "Actor.h"
#include "Vector2D.h"
#include "SDL.h"

#define PI 3.14159265358979323846



class Asteroid : public Actor
{

public:
	Asteroid();
	Asteroid(int x, int y);
	Asteroid(const char* texturesheet, int x, int y, int sc);
	~Asteroid();

	//void Update();
	void Render();
	void EventDispatch(SDL_Event& e);
	void InitComponents() override;
	void InitComponents(int x, int y) override;
	//float GetAngle(int x1, int y1, int x2, int y2);
	//void Rotate(SDL_Texture* texture, int x, int y, float angle);

	

private:
	

};

