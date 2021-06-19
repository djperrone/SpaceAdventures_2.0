#include "sapch.h"
#include "InputController.h"


//void InputController::BindAxisMapping(SDL_Scancode code, Command&& command)
//{
//	m_AxisMappings.emplace_back( code, command );
//}
//
//void InputController::BindActionMapping(SDL_Scancode code, Command&& command)
//{
//	//m_ActionMappings.emplace_back(code, command);
//}

//void InputController::Update()
//{
//	/*for (auto& mapping : m_AxisMappings)
//	{
//		if (IsPressed(mapping) && !WasPressed(mapping))
//		{
//			mapping.GetCommand().Execute();
//		}
//		else if (WasPressed(mapping) && !IsPressed(mapping))
//		{
//			mapping.GetCommand().OnExit();
//		}
//		else
//		{
//
//		}
//	}*/
//
//	for (auto& [key, command] : m_InputMap)
//	{
//		if (IsPressed(key))
//		{
//			command.Execute();
//		}
//	}
//}

//bool InputController::IsPressed(SDL_Scancode code)
//{
//	return m_CurrentKeyBoardState[code];
//}

//bool InputController::IsPressed(const InputMapping& code)
//{
//	return m_CurrentKeyBoardState[code.GetKey()];
//}

//bool InputController::WasPressed(SDL_Scancode code)
//{
//	return m_PreviousKeyBoardState[code];
//}

std::unordered_map<SDL_Scancode, Command>& InputController::GetInputMappings()
{
	return m_InputMap;
}

const std::unordered_map<SDL_Scancode, Command>& InputController::GetInputMappings() const
{
	return m_InputMap;

}

//bool InputController::WasPressed(const InputMapping& code)
//{
//	return m_PreviousKeyBoardState[code.GetKey()];
//}