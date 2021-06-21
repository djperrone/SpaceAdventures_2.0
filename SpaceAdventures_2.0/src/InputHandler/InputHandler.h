#pragma once
#include <SDL_scancode.h>
#include "InputController.h"
//#include "InputHandler/InputListener.h"
//#include "GameManagers/GameManager.h"

class InputHandler
{
public:
	InputHandler();
	void SetInputModeToGame();
	void SetInputModeToUI();	
	bool IsPressed(SDL_Scancode);
	void Update();	
	InputController* GetInputController() const;

private:
	std::unique_ptr<InputController> m_InputController;
	const Uint8* m_CurrentKeyBoardState;
	const Uint8* m_PreviousKeyBoardState;
	
};