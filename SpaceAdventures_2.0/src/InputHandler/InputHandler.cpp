#include "sapch.h"
#include "InputHandler.h"

InputHandler::InputHandler()
{
	//m_KeyBoardState = SDL_GetKeyboardState(NULL);
	m_CurrentKeyBoardState = SDL_GetKeyboardState(NULL);


}

void InputHandler::SetInputModeToGame()
{
	m_InputController.reset(new PlayerController());
}

void InputHandler::SetInputModeToUI()
{
	m_InputController.reset(new UIController());
}

void InputHandler::Update()
{
	for (auto& [key, command] : m_InputController->GetInputMappings())
	{
		if (IsPressed(key))
		{
			command.Execute();
		}
	}
}

InputController* InputHandler::GetInputController() const
{
	return m_InputController.get();
}

bool InputHandler::IsPressed(SDL_Keycode key)
{
	return m_CurrentKeyBoardState[key];
}