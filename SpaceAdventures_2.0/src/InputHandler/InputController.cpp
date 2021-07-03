#include "sapch.h"
#include "InputController.h"

using EventType = SDL_EventType;
//using ActionInputMap = std::unordered_map<EventType, std::unordered_map<InputControlCodes, ActionInputCommand >>;


std::unordered_map<SDL_Scancode, AxisInputCommand>& InputController::GetAxisInputMappings()
{
	return m_AxisInputMap;
}

const std::unordered_map<SDL_Scancode, AxisInputCommand>& InputController::GetAxisInputMappings() const
{
	return m_AxisInputMap;

}

std::unordered_map<EventType, std::unordered_map<SDL_Scancode, ActionInputCommand>> InputController::GetKeyActionInputMappings() const
{
	return m_KeyActionBindings;
}

std::unordered_map<EventType, std::unordered_map<Uint8, ActionInputCommand>> InputController::GetMouseActionInputMappings() const
{
	return m_MouseActionBindings;
}

void InputController::Reset()
{
	m_ActionBindings.clear();
	m_AxisInputMap.clear();
}

//ActionInputMap& InputController::GetActionInputMappings()
//{
//	return m_ActionInputMap;
//
//}
////const std::unordered_map<EventType, ActionInputCommand>& InputController::GetActionInputMappings() const
//{
//	return m_ActionInputMap;
//
//}

