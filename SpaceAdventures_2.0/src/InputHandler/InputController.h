#pragma once
#include "Command.h"
#include <SDL_scancode.h>

#include "SDL.h"

//enum class InputEventType

enum class MouseButton : Uint8
{
	None = 0,
	Left = SDL_BUTTON_LEFT,
	Middle = SDL_BUTTON_MIDDLE,
	Right = SDL_BUTTON_RIGHT	
};




class InputController
{
public:

	InputController()
	{

	}

	using EventType = SDL_EventType;
	//using ActionInputMap = std::unordered_map<EventType, std::unordered_map<InputControlCodes, ActionInputCommand >>;
	
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

	//template <typename... T>
	//void BindActionKeyMapping(SDL_Scancode keyCode, InputEventType type, T&& ...args)
	//{
	//	
	//}

	//template <typename... T>
	//void BindActionKeyMapping(InputControlCodes button, EventType type, T&&... args)
	//{
	//	//SDL_BUTTON(button);
	//	m_ActionInputMap[type][button] = static_cast<ActionInputCommand>(std::bind(args...));
	//	
	//}

	//template <typename... T>
	//void BindActionKeyMapping(SDL_Scancode keyCode, EventType type, T&&... args)
	//{
	//	//SDL_BUTTON(button);
	//	std::cout << "keycode\n";
	//	m_KeyActionBindings[type][keyCode] = static_cast<ActionInputCommand>(std::bind(args...));

	//}
	//template <typename... T>
	//void BindActionKeyMapping1(SDL_Scancode keyCode, EventType type, T&&... args)
	//{
	//	//SDL_BUTTON(button);
	//	std::cout << "keycode\n";
	//	m_KeyActionBindings[type][keyCode] = static_cast<ActionInputCommand>(std::bind(args...));

	//}

	//template <typename... T>
	//void BindActionKeyMapping(MouseButton button, EventType type, T&&... args)
	//{
	//	//SDL_BUTTON(button);
	//	m_MouseActionBindings[type][static_cast<Uint8>(button)] = static_cast<ActionInputCommand>(std::bind(args...));

	//}

	//template <typename... T>
	//void BindActionKeyMapping(MouseButton button, EventType type, T&&... args)
	//{
	//	//SDL_BUTTON(button);

	//}

	virtual std::unordered_map<SDL_Scancode, AxisInputCommand>& GetAxisInputMappings();
	virtual const std::unordered_map<SDL_Scancode, AxisInputCommand>& GetAxisInputMappings() const;
	std::unordered_map<EventType, std::unordered_map<SDL_Scancode, ActionInputCommand>> GetKeyActionInputMappings() const;
	std::unordered_map<EventType, std::unordered_map<Uint8, ActionInputCommand>> GetMouseActionInputMappings() const;

	//virtual ActionInputMap& GetActionInputMappings();
	//virtual const std::unordered_map<EventType, ActionInputCommand>& GetActionInputMappings() const;
	std::unordered_map<EventType, std::vector<ActionInputCommand>> GetActionInputBindingsVec()
	{
		return m_ActionBindings;
	}

protected:	
	const Uint8* m_CurrentKeyBoardState;
	const Uint8* m_PreviousKeyBoardState;
	std::unordered_map<SDL_Scancode, AxisInputCommand> m_AxisInputMap;
	///std::unordered_map<EventType, ActionInputCommand> m_ActionInputMap;
	std::unordered_map<EventType, std::vector<ActionInputCommand> > m_ActionBindings;

	std::unordered_map<EventType, std::unordered_map<SDL_Scancode, ActionInputCommand>> m_KeyActionBindings;
	std::unordered_map<EventType, std::unordered_map<Uint8, ActionInputCommand>> m_MouseActionBindings;
	//ActionInputMap m_ActionInputMap;

	//std::array<std::unordered_map<SDL_EventType, ActionInputCommand>,4> m_NewActionBindings;

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

	//PlayerController(Player* player)

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

