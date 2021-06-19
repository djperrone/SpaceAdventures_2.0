#pragma once
#include <functional>

class Command
{
public:	
	Command() {}
	Command(std::function<void()>&& func)
		: m_Command(func) {}
	
	Command(const Command& func)
		: m_Command(func.Get()) {}

	virtual ~Command() {}

	virtual void Execute()
	{
		m_Command();
	}

	virtual void OnExit() {}

	std::function<void()> Get() const
	{
		return m_Command;
	}

private:
	std::function<void()> m_Command;
};