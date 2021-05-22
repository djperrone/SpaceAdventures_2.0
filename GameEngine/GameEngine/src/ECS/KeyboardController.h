#pragma once
#include "SDL.h"
#include "MyObjects/Player.h"

class GameObject;
class KeyboardController
{
public:
	KeyboardController(Player* player);
	void UpdateLocation(SDL_Event& e);
private:
	bool w = false;
	bool a = false;
	bool s = false;
	bool d = false;
	bool r = false;
	bool clicked = false;
	Player* m_Player;
};
