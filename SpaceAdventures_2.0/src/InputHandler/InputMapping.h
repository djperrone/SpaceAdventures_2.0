#pragma once
#include <SDL_scancode.h>
#include "Command.h"		
class InputMapping
{
public:
	InputMapping();
	InputMapping(SDL_Scancode, std::function<void()>&& command);
	InputMapping(SDL_Scancode, const Command& command);

	SDL_Scancode GetKey() const;
	Command& GetCommand();
	const Command& GetCommand() const;


protected:
	Command m_Command;
	SDL_Scancode m_Key;
};

class ActionMapping : public InputMapping
{
public:

	ActionMapping();
	ActionMapping(SDL_Scancode, std::function<void()>&& command);
	ActionMapping(SDL_Scancode, const Command& command);

	SDL_Scancode GetKey() const;
	Command& GetCommand();
	const Command& GetCommand() const;

	
};

class AxisMapping : public InputMapping
{
public:
	AxisMapping();
	AxisMapping(SDL_Scancode, std::function<void()>&& command);
	AxisMapping(SDL_Scancode, const Command& command);

	SDL_Scancode GetKey() const;
	Command& GetCommand();
	const Command& GetCommand() const;
};