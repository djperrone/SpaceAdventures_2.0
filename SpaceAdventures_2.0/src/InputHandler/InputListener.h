#pragma once
#include <SDL.h>

class InputListener
{
public:
	//InputListener() {}

	static void CreateInputListener()
	{
		if (s_Instance == nullptr)
			s_Instance = new InputListener();
	}
	static InputListener* GetInputListener()
	{		
		if (s_Instance == nullptr)
			s_Instance = new InputListener();
		return s_Instance;
	}

	static SDL_Event GetEvent()
	{
		return m_Event;
	}

	static void PollEvents()
	{
		SDL_PollEvent(&m_Event);

		/*switch (m_Event.type)
		{		
		default:
			break;
		}*/
	}
	static bool IsMouseClicked;
	static SDL_Event m_Event;
private:
	static InputListener* s_Instance;
};