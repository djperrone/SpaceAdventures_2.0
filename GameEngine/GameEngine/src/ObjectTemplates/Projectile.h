#pragma once
#include "ObjectTemplates/Actor.h"
#include "../Vector3D.h"

class Projectile : public Actor
{
public:
	Projectile();
	Projectile(int xpos, int ypos, float direction, Team team);

	Projectile(Vector2D position, int width, int height, float scale, int xVel, int yVel, float speed, float health, float damage, Team team);
	Projectile(Vector2D position, Vector2D velocity, Team team);


	//Projectile(int xpos, int ypos, Vector2D direction, Team team);

	//Projectile(Vector2D position, Vector2D direction, Team team);

	//Projectile(Vector2D position, Vector3D<int,int,float> dimensions,Vector3D<int, int, float> velocity, float health, float damage, Team team);



	~Projectile();


protected:

};

