#include "sapch.h"
#include "Button.h"

Button::Button()
{
}

Button::Button(const char* fileName, ButtonType type, float xPos, float yPos, int width, int height, float scale)
	:m_ButtonType(type)
{
	InitComponents(fileName, xPos, yPos, width, height, scale, 0);

}

Button::~Button()
{
}

void Button::Update()
{
}

void Button::HandleEvent()
{
}
