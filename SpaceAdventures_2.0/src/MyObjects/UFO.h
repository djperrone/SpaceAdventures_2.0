#pragma once
#include "MyObjects/Ship.h"

class UFO : public Ship
{
public:
	UFO();
	~UFO();
	UFO(int x, int y);
	void Update() override;

	

private:
	time_t currentTime;
	time_t previousTime;
	double FIRE_RATE = 3;
};

