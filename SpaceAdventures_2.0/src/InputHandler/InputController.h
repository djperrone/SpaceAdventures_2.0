#pragma once
#include "Command.h"
#include <SDL_scancode.h>
#include <functional>

class InputController
{
public:
	//auto& BindKeyMapping = std::bind;
	template <typename... T>
	void BindKeyMappings(SDL_Scancode code, T&&... args)
	{
		//return std::bind(args...);
		m_InputMap.insert(code, std::bind(args...));
	}

	virtual void Update();
	virtual bool IsPressed(SDL_Scancode code);
	virtual bool WasPressed(SDL_Scancode code);

	virtual std::unordered_map<SDL_Scancode, Command*>& GetInputMappings();
	virtual const std::unordered_map<SDL_Scancode, Command*>& GetInputMappings() const;

	


private:	
	const Uint8* m_CurrentKeyBoardState;
	const Uint8* m_PreviousKeyBoardState;
	std::unordered_map<SDL_Scancode, Command*> m_InputMap;
};

class PlayerController : public InputController
{
public:
	/*virtual void MoveLeft();
	virtual void MoveRight();
	virtual void MoveUp();
	virtual void MoveDown();*/

private:

};

class AIController : public InputController
{

};

class UIController : public InputController
{
public:

private:

};