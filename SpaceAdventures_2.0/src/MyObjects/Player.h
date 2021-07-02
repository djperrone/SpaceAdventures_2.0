#pragma once
#include "MyObjects/Ship.h"
#include "Dimensions.h"
#include "InputHandler/InputController.h"

class Character;

class Player : public Ship
{

public:	
	Player(Character* mouseCursor, InputController* inputController);
	Player(std::string imageFile, int x, int y);

	virtual void Update() override;
	void SetupPlayerInput();

	~Player();
	bool Paused = false;

	virtual bool FireGun() override;


	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Pause();
	bool Reload();


private:
	InputController* m_InputController;
	Dimensions dimensions;
	Character* m_MouseCursor;
	Vector2D m_PreviousPosition;

};

