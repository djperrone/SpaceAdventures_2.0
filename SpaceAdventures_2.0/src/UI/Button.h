#pragma once
#include "ObjectTemplates/Character.h"

enum class ButtonType
{
	None = 0,
	Play,
	PauseMenu,
	MainMenu,
	Exit
};

class Button : public Actor
{
public:
	Button();
	Button(const char* fileName, ButtonType type, float xPos, float yPos, int width, int height, float scale);
	virtual ~Button();
	virtual void Update() override;
	void HandleEvent();
	ButtonType m_ButtonType;
private:

};