#include "sapch.h"
#include "StaticSprite.h"

StaticSprite::StaticSprite()
{
}

StaticSprite::StaticSprite(const char* fileName, float xPos, float yPos, int width, int height, float scale)
{
	InitComponents(fileName, xPos, yPos, width, height, scale,0);
}

StaticSprite::~StaticSprite()
{
}

void StaticSprite::Update()
{
}
