#pragma once
#include <functional>
#include <SDL.h>
#include "Command.h"
#include "InputController.h"

class InputHandler
{
	InputHandler();
	void SetInputModeToGame();
	void SetInputModeToUI();
	void HandleInput();
	bool IsPressed(SDL_Keycode);
	void HandleEvent(SDL_Keycode key);
	void HandleAllEvents();

	virtual void Update();
	
	void SetKeyBinding(SDL_Scancode, Command*);

private:
	std::unique_ptr<InputController> m_InputController;
	const Uint8* m_CurrentKeyBoardState;
	const Uint8* m_PreviousKeyBoardState;
	
};