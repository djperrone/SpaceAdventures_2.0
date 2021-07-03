#pragma once
#include "Command.h"
#include <SDL_scancode.h>


class InputController
{
public:

	InputController()
	{

	}
		using EventType = SDL_EventType;
	
	
	template <typename... T>
	void BindAxisKeyMapping(SDL_Scancode code, T&&... args)
	{
	
		m_AxisInputMap[code] = static_cast<AxisInputCommand>(std::bind(args...));
	}	

	template <typename... T>
	void BindActionKeyMapping(EventType e, T&&... args)
	{		
		m_ActionBindings[e].push_back(static_cast<ActionInputCommand>(std::bind(args...)));
	}

	

	virtual std::unordered_map<SDL_Scancode, AxisInputCommand>& GetAxisInputMappings();
	virtual const std::unordered_map<SDL_Scancode, AxisInputCommand>& GetAxisInputMappings() const;
	std::unordered_map<EventType, std::unordered_map<SDL_Scancode, ActionInputCommand>> GetKeyActionInputMappings() const;
	std::unordered_map<EventType, std::unordered_map<Uint8, ActionInputCommand>> GetMouseActionInputMappings() const;

	std::unordered_map<EventType, std::vector<ActionInputCommand>> GetActionInputBindingsVec()
	{
		return m_ActionBindings;
	}
	void Reset();


protected:	
	const Uint8* m_CurrentKeyBoardState;
	const Uint8* m_PreviousKeyBoardState;
	std::unordered_map<SDL_Scancode, AxisInputCommand> m_AxisInputMap;
	///std::unordered_map<EventType, ActionInputCommand> m_ActionInputMap;
	std::unordered_map<EventType, std::vector<ActionInputCommand> > m_ActionBindings;

	std::unordered_map<EventType, std::unordered_map<SDL_Scancode, ActionInputCommand>> m_KeyActionBindings;
	std::unordered_map<EventType, std::unordered_map<Uint8, ActionInputCommand>> m_MouseActionBindings;

};

class PlayerController : public InputController
{
public:

private:

};

class AIController : public InputController
{

};

class UIController : public InputController
{
public:

private:

};

