#pragma once
#include <functional>
#include <SDL.h>
#include "Command.h"
#include "InputController.h"

class InputHandler
{
public:
	InputHandler();
	void SetInputModeToGame();
	void SetInputModeToUI();	
	bool IsPressed(SDL_Keycode);
	void Update();	
	InputController* GetInputController() const;

private:
	std::unique_ptr<InputController> m_InputController;
	const Uint8* m_CurrentKeyBoardState;
	const Uint8* m_PreviousKeyBoardState;
	
};