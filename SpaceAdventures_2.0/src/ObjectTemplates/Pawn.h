#pragma once
#include "Actor.h"

#include "ECS/ComponentManager.h"
#define PI 3.14159265358979323846



class Pawn : public Actor
{

public:	
	Pawn();
	Pawn(const std::string& texturesheet, int x, int y);
	virtual ~Pawn();

	void Update();
	
	//float GetAngle(int x1, int y1, int x2, int y2);
	//void Rotate(SDL_Texture* texture, int x, int y, float angle);

	virtual void InitComponents();	
	//virtual void InitComponents(float xPos, float yPos, float direction,int width, int height, float scale, float speed, float xVel, float yVel, float health, float damage) override;




private:

	
};
