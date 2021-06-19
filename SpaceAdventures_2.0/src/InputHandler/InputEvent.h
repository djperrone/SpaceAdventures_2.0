#pragma once
#include <functional>
#include "Event.h"
//template <typename T>
class InputEvent 
{
public:
	// takes function as parameter?
	InputEvent(const std::function<void()>& func)
	: m_Event(func) {}
	virtual ~InputEvent() {}
	virtual void Execute()
	{
		m_Event();
	}
	
		
private:
	std::function<void()> m_Event;
};