#include "sapch.h"
#include "InputHandler/Command.h"

AxisInputCommand::AxisInputCommand()
{
}

AxisInputCommand::AxisInputCommand(std::function<void()>&& func)
	: m_Command(func) {}

AxisInputCommand::AxisInputCommand(const AxisInputCommand& func)
	: m_Command(func.Get()) {}

AxisInputCommand::~AxisInputCommand() {}

void AxisInputCommand::Execute()
{
	m_Command();
}

std::function<void()> AxisInputCommand::Get() const
{
	return m_Command;
}

ActionInputCommand::ActionInputCommand()
{
	/*for (auto& i : m_Actions)
	{
		i = Command(nullptr);
	}*/
}

//ActionInputCommand::ActionInputCommand(SDL_EventType eventType, SDL_Scancode code, std::function<bool()>&& func)
//	: m_EventType(eventType), m_Scancode(code), m_MouseButton(-1), m_Command(func)
//{
//}

ActionInputCommand::ActionInputCommand(SDL_EventType eventType, std::function<bool()>&& func)
	: m_EventType(eventType), m_Command(func)
{
}

ActionInputCommand::ActionInputCommand(std::function<bool()>&& func)
	: m_Command(func) {}


ActionInputCommand::ActionInputCommand(const ActionInputCommand& func)
	: m_Command(func.Get()) {}


ActionInputCommand::~ActionInputCommand()
{
}

void ActionInputCommand::OnPress()
{
}

void ActionInputCommand::OnRepeat()
{
}

void ActionInputCommand::OnRelease()
{
}

std::function<bool()> ActionInputCommand::Get() const
{
	return m_Command;
}

bool ActionInputCommand::Execute()
{	
	return m_Command();
}
