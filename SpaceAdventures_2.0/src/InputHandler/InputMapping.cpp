#include "sapch.h"
#include "InputMapping.h"

InputMapping::InputMapping()
	: m_Key(SDL_SCANCODE_UNKNOWN), m_Command(nullptr)
{
}

InputMapping::InputMapping(SDL_Scancode code, std::function<void()>&& command)
	: m_Key(code), m_Command(std::move(command))
{
	
}

InputMapping::InputMapping(SDL_Scancode code, const Command& command)
	: m_Key(code), m_Command(command)
{
}

SDL_Scancode InputMapping::GetKey() const
{
	return m_Key;
	
}

Command& InputMapping::GetCommand()
{
	return m_Command;
}

const Command& InputMapping::GetCommand() const
{
	return m_Command;
}
