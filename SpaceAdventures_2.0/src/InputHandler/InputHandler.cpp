#include "sapch.h"
#include "InputHandler.h"
//#include "GameManagers/GameManager.h"
#include "EventListener.h"

#include "Command.h"


InputHandler::InputHandler()
{	
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
	for (auto& [key, command] : m_InputController->GetAxisInputMappings())
	{
		if (IsPressed(key))
		{
			command.Execute();
		}
	}

	for (auto [type, commandVec] : m_InputController->GetActionInputMappings())
	{
		if (type == EventListener::Event.type)//InputListener::m_Event.type)
		{
			for (auto action : commandVec)
			{
				if (EventListener::Event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (!EventListener::IsMouseRepeating)
					{
						if (action.Execute());
						std::cout << "Exevute\n";
						return;
					}
				}
				else 
				{
					if(action.Execute());
					std::cout << "Exevute\n";
					return;
				}
			}
		}
	}

	/*if (m_InputController->GetActionInputMappings().find(EventListener::Event) != m_InputController->GetActionInputMappings().end())
	{

	}*/

	//for(auto& someEvent : m_InputController->GetActionInputMappings()[])


	//SDL_Event event;

	//while (SDL_PollEvent(&EventListener::Event))
	//{
	//	/*switch (EventListener::Event.type)
	//	{
	//	case SDL_MOUSEBUTTONDOWN:
	//		std::cout << "Mouse Button down InptuHandler!\n";

	//		if (EventListener::IsMouseClicked != true)
	//		{
	//			if (m_InputController->GetActionInputMappings().find(SDL_MOUSEBUTTONDOWN) != m_InputController->GetActionInputMappings().end())
	//			{
	//				m_InputController->GetActionInputMappings()[SDL_MOUSEBUTTONDOWN].Execute();
	//			}

	//			EventListener::IsMouseClicked = true;
	//		}
	//		break;


	//	case SDL_MOUSEBUTTONUP:		
	//		
	//			if (m_InputController->GetActionInputMappings().find(SDL_MOUSEBUTTONUP) != m_InputController->GetActionInputMappings().end())
	//			{
	//				m_InputController->GetActionInputMappings()[SDL_MOUSEBUTTONUP].Execute();
	//			}

	//			EventListener::IsMouseClicked = false;
	//		
	//	}*/
	//}
	////for (auto& [event, command] : m_InputController->GetActionInputMappings())
	//{
	//	if (event == EventListener::Event.type)
	//	{
	//		if (event == SDL_MOUSEBUTTONDOWN && !EventListener::IsMouseClicked)
	//		{
	//			command.Execute();
	//		}
	//		
	//		/*switch (*event)
	//		{
	//		case SDL_MOUSEBUTTONDOWN:
	//			if (event = EventListener::Event.button.button)
	//				command.Execute();
	//			break;
	//		case SDL_MOUSEBUTTONUP:
	//			break;*/
	//		/*case SDL_KEYDOWN:
	//			break;*/
	//		//}
	//	}
	//}
}

InputController* InputHandler::GetInputController() const
{
	return m_InputController.get();
}

bool InputHandler::IsPressed(SDL_Scancode key)
{
	return m_CurrentKeyBoardState[key];
}