#pragma once
#include <SDL_scancode.h>
#include "InputController.h"

class InputHandler
{
public:
	InputHandler();
	void SetInputModeToGame();
	void SetInputModeToUI();	
	void SetController(InputController* controller);
	bool IsPressed(SDL_Scancode);
	void Update();	
	InputController* GetInputController() const;

private:
	std::unique_ptr<InputController> m_InputController;

	std::unordered_map<Uint8, bool> m_KeyActionState;

	const Uint8* m_CurrentKeyBoardState;
	const Uint8* m_PreviousKeyBoardState;
	
};