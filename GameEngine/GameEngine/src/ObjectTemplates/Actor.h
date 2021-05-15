#pragma once
#include "GameObject.h"
#include "ECS/ComponentManager.h"
#include "Vector2D.h"
#include "SDL.h"

#define PI 3.14159265358979323846



class Actor : public GameObject
{

public:
	Actor();
	Actor(int x, int y);
	Actor(const std::string& texturesheet, int x, int y);
	virtual void InitComponents(int x, int y) override;


	~Actor();

	void Update() override;	
	virtual void InitComponents() override;
	virtual void InitComponents(float xPos, float yPos, int width, int height, float scale, float speed, float xVel, float yVel) override;

	//virtual void InitComponents(const std::string& texturesheet, int x, int y, float width, float height, float scale, float speed) override;

	inline bool IsCollidable() const { return collidable; }

protected:
	bool collidable;
private:
	//collision component
	

};

