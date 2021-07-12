#include "sapch.h"
#include "InputHandler.h"
#include "EventListener.h"
#include "Game.h"

#include "Command.h"


InputHandler::InputHandler()
{	
	m_CurrentKeyBoardState = SDL_GetKeyboardState(NULL);
	m_InputController = std::make_unique<InputController>();
}

void InputHandler::SetInputModeToGame()
{
	m_InputController.reset(new PlayerController());	
}

void InputHandler::SetController(InputController* controller)
{
	m_InputController.reset(controller);
}

void InputHandler::SetInputModeToUI()
{
	m_InputController.reset(new UIController());	
}

InputController* InputHandler::GetInputController() const
{
	return m_InputController.get();
}

bool InputHandler::IsPressed(SDL_Scancode key)
{
	return m_CurrentKeyBoardState[key];
}

void InputHandler::Update()
{
	for (auto& [key, command] : m_InputController->GetAxisInputMappings())
	{
		if (IsPressed(key))
		{
			command.Execute();
		}
	}

	while (SDL_PollEvent(&EventListener::Event))
	{
		if (EventListener::Event.type == SDL_QUIT)
		{
			Game::isRunning = false;
		}

		for (auto& [event, mouseBinding] : m_InputController->GetActionInputMappings())
		{
			if (EventListener::Event.type == event)
			{
				if (EventListener::Event.type == SDL_KEYDOWN && EventListener::Event.key.repeat != 0)
				{
					continue;
				}
				
				for (auto& [key, command] : mouseBinding)
				{
					if (EventListener::Event.button.button == key)
					{
						command.Execute();

					}
				}
				
			}
		}		
	}	
}

