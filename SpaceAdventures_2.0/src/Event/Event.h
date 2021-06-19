#pragma once
#include <functional>

class Event
{
public:

	virtual void Execute() = 0;

private:
	
};

class InputEvent : public Event
{
public:
	virtual void Execute() override;

private:

};

class CustomEvent : public Event
{
	virtual void Execute() override;

};

