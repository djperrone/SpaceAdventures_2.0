#pragma once
#include "Command.h"
#include <SDL_scancode.h>

#include "SDL.h"


enum class InputType
{
	None = 0,
	AxisInput,
	ActionInput
};

class InputController
{
public:

	using EventType = SDL_EventType;
	
	template <typename... T>
	void BindAxisKeyMapping(SDL_Scancode code, T&&... args)
	{
		//return std::bind(args...);
		m_AxisInputMap[code] = static_cast<AxisInputCommand>(std::bind(args...));
	}	

	template <typename... T>
	void BindActionKeyMapping(EventType e, T&&... args)
	{
		//return std::bind(args...);
		m_ActionBindings[e].push_back(static_cast<ActionInputCommand>(std::bind(args...)));
	}

	virtual std::unordered_map<SDL_Scancode, AxisInputCommand>& GetAxisInputMappings();
	virtual const std::unordered_map<SDL_Scancode, AxisInputCommand>& GetAxisInputMappings() const;

	virtual std::unordered_map<SDL_EventType, std::vector<ActionInputCommand>>& GetActionInputMappings();
	//virtual const std::unordered_map<EventType, ActionInputCommand>& GetActionInputMappings() const;

protected:	
	const Uint8* m_CurrentKeyBoardState;
	const Uint8* m_PreviousKeyBoardState;
	std::unordered_map<SDL_Scancode, AxisInputCommand> m_AxisInputMap;
	///std::unordered_map<EventType, ActionInputCommand> m_ActionInputMap;
	std::unordered_map<EventType, std::vector<ActionInputCommand> > m_ActionBindings;

	//std::unordered_map<EventType, std::string> m_FunctionNameBindings;
	//std::unordered_map<std::string, ActionInputCommand> m_ActionInputBindings;
	//std::vector<ActionInputCommand> m_ActionBindings;
	

	//std::vector<std::unordered_map<SDL_Event, ActionInputCommand>> m_ActionMappings;
	//std::unordered_map<std::string, ActionInputCommand> m_ActionBinding;
};

class PlayerController : public InputController
{
public:
	/*virtual void MoveLeft();
	virtual void MoveRight();
	virtual void MoveUp();
	virtual void MoveDown();*/

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

