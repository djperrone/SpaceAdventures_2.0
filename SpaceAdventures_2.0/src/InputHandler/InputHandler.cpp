#include "sapch.h"
#include "InputHandler.h"

InputHandler::InputHandler()
{
	//m_KeyBoardState = SDL_GetKeyboardState(NULL);
	

}

void InputHandler::SetInputModeToGame()
{
	m_InputController.reset(new PlayerController());
}

void InputHandler::SetInputModeToUI()
{
	m_InputController.reset(new UIController());
}

void InputHandler::HandleInput()
{

}

void InputHandler::Update()
{
	for (auto& [key, command] : m_InputController->GetInputMappings())
	{
		if (IsPressed(key))
		{
			command->Execute();
		}
	}
}

bool InputHandler::IsPressed(SDL_Keycode key)
{
	return m_CurrentKeyBoardState[key];
}

//void InputHandler::HandleEvent(SDL_Keycode key)
//{
//	/*if (m_KeyBindings.find(key) != m_KeyBindings.end())
//	{
//		auto event = m_KeyBindings[key];
//		event->Execute();
//	}*/
//}
//
//void InputHandler::HandleAllEvents()
//{
//	for (int i = 0; i < 250; i++)
//	{
//		if (m_KeyBoardState[i])
//		{
//			HandleEvent(i);
//		}
//	}
//}

//void InputHandler::SetKeyBinding(SDL_Keycode code, Command* command)
//{
//	//m_KeyBindings.insert({ code, command });
//}
