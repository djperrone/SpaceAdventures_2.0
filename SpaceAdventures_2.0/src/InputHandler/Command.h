#pragma once

class Command
{
public:	
	Command();

	Command(std::function<void()>&& func);		
	
	Command(const Command& func);		

	virtual ~Command();

	virtual void Execute();	

	virtual std::function<void()> Get() const;
	

protected:
	std::function<void()> m_Command;
};

class AxisInputCommand 
{
public:
	AxisInputCommand();

	AxisInputCommand(std::function<void()>&& func);

	AxisInputCommand(const AxisInputCommand& func);

	~AxisInputCommand();

	void Execute();

	virtual std::function<void()> Get() const;
private:
	std::function<void()> m_Command;

};

// need sdl event - up, down, repeat, need bool functino condition (if mouselocation here), (if !reloading), need action Function

enum class ActionState
{
	None = 0,
	Press = 1,
	Repeat = 2,
	Release = 3

};

// Action InputCommand("Fire",key_press, this, &FireGun)

class ActionInputCommand 
{
public:

	ActionInputCommand();

	//ActionInputCommand(SDL_EventType event, SDL_Scancode code, std::function<bool()>&& func);
	ActionInputCommand(SDL_EventType event,std::function<bool()>&& func);

	ActionInputCommand(std::function<bool()>&& func);

	ActionInputCommand(const ActionInputCommand& func);

	~ActionInputCommand();

	std::array<std::function<bool()>, 4> m_Actions;

	void OnPress();
	void OnRepeat();
	void OnRelease();
	bool Execute();

	std::string m_FunctionName;



	virtual std::function<bool()> Get() const;
private:
	std::function<bool()> m_ActionCondition;
	std::function<bool()> m_Command;
	std::function<void()> m_Action;
	SDL_Scancode m_Scancode;
	SDL_EventType m_EventType;
	Uint8 m_MouseButton;

	/*std::function<void()> m_PressCommand;
	std::function<void()> m_RepeatCommand;
	std::function<void()> m_ReleaseCommand;*/

	//std::array<Command,4> m_Actions;

};