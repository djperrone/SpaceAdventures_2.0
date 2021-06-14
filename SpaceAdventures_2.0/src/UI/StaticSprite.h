#pragma once
#include "ObjectTemplates/GameObject.h"

class StaticSprite : public GameObject
{
public:
	StaticSprite();
	StaticSprite(const char* fileName, float xPos, float yPos, int width, int height, float scale);
	virtual ~StaticSprite();
	virtual void Update() override;


private:

};