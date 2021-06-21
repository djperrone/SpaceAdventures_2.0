#include "sapch.h"
#include "InputController.h"

using EventType = SDL_EventType;

std::unordered_map<SDL_Scancode, AxisInputCommand>& InputController::GetAxisInputMappings()
{
	return m_AxisInputMap;
}

const std::unordered_map<SDL_Scancode, AxisInputCommand>& InputController::GetAxisInputMappings() const
{
	return m_AxisInputMap;

}

std::unordered_map<SDL_EventType, std::vector<ActionInputCommand>>& InputController::GetActionInputMappings()
{
	return m_ActionBindings;

}
//const std::unordered_map<EventType, ActionInputCommand>& InputController::GetActionInputMappings() const
//{
//	return m_ActionInputMap;
//
//}

