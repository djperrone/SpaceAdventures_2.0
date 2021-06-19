#pragma once
#include "MyObjects/Ship.h"
#include "Dimensions.h"
#include "InputHandler/InputController.h"

class Character;

class Player : public Ship
{

public:	
	Player(Character* mouseCursor);
	Player(std::string imageFile, int x, int y);

	virtual void Update() override;

	~Player();
	bool Paused = false;

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

private:
	InputController* m_InputController;
	Dimensions dimensions;
	Character* m_MouseCursor;
};

