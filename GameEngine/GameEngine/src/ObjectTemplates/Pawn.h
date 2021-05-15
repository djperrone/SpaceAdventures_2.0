#pragma once
#include "Actor.h"
#include "Vector2D.h"
#include "SDL.h"

#include "ECS/ComponentManager.h"
#define PI 3.14159265358979323846



class Pawn : public Actor
{

public:	
	Pawn();
	Pawn(const std::string& texturesheet, int x, int y);
	~Pawn();

	void Update();
	
	//float GetAngle(int x1, int y1, int x2, int y2);
	//void Rotate(SDL_Texture* texture, int x, int y, float angle);

	virtual void InitComponents();	



private:

	
};

