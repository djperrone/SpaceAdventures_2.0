#pragma once
#include "MyObjects/Ship.h"

#include "Dimensions.h"

class MouseCursor;

class Player : public Ship
{

public:	
	Player(MouseCursor* mouseCursor);
	Player(std::string imageFile, int x, int y);

	virtual void Update() override;

	~Player();

private:
	Dimensions dimensions;
	MouseCursor* m_MouseCursor;
};

