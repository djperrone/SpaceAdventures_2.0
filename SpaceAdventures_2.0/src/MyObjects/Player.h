#pragma once
#include "MyObjects/Ship.h"
#include "Dimensions.h"

class Character;

class Player : public Ship
{

public:	
	Player(Character* mouseCursor);
	Player(std::string imageFile, int x, int y);

	virtual void Update() override;

	~Player();

private:
	Dimensions dimensions;
	Character* m_MouseCursor;
};

