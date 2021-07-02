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
	SDL_FlushEvents(0, 255);
	m_InputController.reset(new PlayerController());
}

void InputHandler::SetController(InputController* controller)
{
	m_InputController.reset(controller);
}

void InputHandler::SetInputModeToUI()
{
	SDL_FlushEvents(0, 255);

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

	for (auto& [event, commandVec] : m_InputController->GetActionInputBindingsVec())
	{
		if (EventListener::Event.type == event)
		{
			for (auto action : commandVec)
			{
				if (action.Execute())
				{
					return;
				}
			}
		}		
	}

	//auto& map = m_InputController->GetActionInputMappings();
	//if (map[EventListener::Event.type])
	//{

	//}
	/*if (EventListener::Event.type == SDL_KEYDOWN)
	{

	}
	switch (EventListener::Event.type)
	{
	case SDL_KEYDOWN:
	}*/

	/*if (EventListener::Event.type == SDL_KEYDOWN)
	{

	}*/
	//auto& map = m_InputController->GetActionInputMappings();
	//if (map.find(static_cast<SDL_EventType>(EventListener::Event.type)) != map.end())
	//{
	//	//map[static_cast<SDL_EventType>(EventListener::Event.type)].
	//}
	auto mouseActionMap = m_InputController->GetMouseActionInputMappings();
	auto KeyActionMap = m_InputController->GetKeyActionInputMappings();	
	//std::cout << "KEY MAP SIZE INPUTHANDLER " << KeyActionMap.size() << std::endl;

	/*if (KeyActionMap.find(SDL_KEYDOWN) != KeyActionMap.end())
	{
		std::cout << "KEYDOWN EVENT INPUTHANDLER\n";
		auto innerMap = KeyActionMap[SDL_KEYDOWN];
		if (innerMap.find(SDL_SCANCODE_R) != innerMap.end())
		{
			std::cout << "INPUT HANDLER R PRESESED\n";
			innerMap[SDL_SCANCODE_R].Execute();
		}
	}*/

	/*for (auto& [event, map] : m_InputController->GetMouseActionInputMappings())
	{
		if (EventListener::Event.type == event)
		{
			if (map.find(EventListener::Event.button.button) != map.end())
			{
				map[EventListener::Event.button.button].Execute();
			}
		}
	}

	for (auto& [event, map] : m_InputController->GetKeyActionInputMappings())
	{
		if (EventListener::Event.type == event)
		{
			if (map.find(EventListener::Event.key.keysym.scancode) != map.end())
			{
				map[EventListener::Event.key.keysym.scancode].Execute();
			}
		}
	}*/

	//switch (EventListener::Event.type)
	//{
	//case SDL_KEYDOWN:
	//	std::cout << "KEYDOWN CASE\n";
	//	if (KeyActionMap.find(SDL_KEYDOWN) != KeyActionMap.end())
	//	{
	//		std::cout << "KEYDOWN EVENT INPUTHANDLER\n";
	//		auto innerMap = KeyActionMap[SDL_KEYDOWN];
	//		if (innerMap.find(SDL_SCANCODE_R) != innerMap.end())
	//		{
	//			std::cout << "INPUT HANDLER R PRESESED\n";
	//			innerMap[SDL_SCANCODE_R].Execute();
	//		}
	//	}
	//	break;
	//case SDL_MOUSEBUTTONDOWN:
	//	std::cout << "MOUSEDOWN CASE\n";

	//	if (mouseActionMap.find(SDL_MOUSEBUTTONDOWN) != mouseActionMap.end())
	//	{
	//		auto innerMap = mouseActionMap[SDL_MOUSEBUTTONDOWN];
	//		if (innerMap.find(SDL_BUTTON_LEFT) != innerMap.end())
	//		{
	//			innerMap[SDL_BUTTON_LEFT].Execute();
	//		}
	//	}
	//	break;

	//case SDL_MOUSEBUTTONUP:
	//	break;	

	//case SDL_KEYUP:
	//	break;
	//}


	
	//for (auto [type, keymap] : m_InputController->GetActionInputBindingsVec())
	//{
	//	if (type == EventListener::Event.type)//InputListener::m_Event.type)
	//	{
	//		for (auto& [key, command] : keymap)
	//		{

	//			if (EventListener::Event.type == SDL_MOUSEBUTTONDOWN)
	//			{
	//				if (!EventListener::IsMouseRepeating)
	//				{
	//					if (action.Execute());
	//					std::cout << "Exevute\n";
	//					return;
	//				}
	//			}
	//			else 
	//			{
	//				if(action.Execute());
	//				std::cout << "Exevute\n";
	//				return;
	//			}
	//		}
	//	}
	//}

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

