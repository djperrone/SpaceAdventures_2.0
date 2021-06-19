#pragma once
#include <queue>
#include "InputEvent.h"

// Move mouse cursor to input?
// make functions in gamestatemachine and player
// remove gamestate machine and player from all menus
// make renderer global static
// All events will take no parameters
// std::function<void(T&>;
// InputEvent class will store templated function
// InputHandler has list of events (events not templated) -> event will have function RunEvent - could have helper class
// auto func1 = std::bind(&Entity::Print, e, 5);
// 

class InputListener
{
public:
	inline static InputListener* GetInputHandler() { return s_Instance; }
	inline static void CreateInputHandler() { if (s_Instance == nullptr) s_Instance = new InputListener(); }
	inline void PushInputEvent(InputEvent* event) { s_InputQueue.push(event); }
	void HandleEvents()
	{
		while (!s_InputQueue.empty())
		{
			s_InputQueue.front()->Execute();
			s_InputQueue.pop();
		}
	}

private:
	static InputListener* s_Instance;
	static std::queue<InputEvent*> s_InputQueue;

};