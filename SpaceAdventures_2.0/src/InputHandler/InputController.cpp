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

