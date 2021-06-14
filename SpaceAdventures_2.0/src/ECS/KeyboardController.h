#pragma once
#include "SDL.h"


class Player;
class KeyboardController
{
public:
	KeyboardController(Player* player);
	~KeyboardController();
	void UpdateLocation(SDL_Event& e);
private:
	bool w = false;
	bool a = false;
	bool s = false;
	bool d = false;
	bool r = false;
	//bool clicked = true;
	Player* m_Player;
};
