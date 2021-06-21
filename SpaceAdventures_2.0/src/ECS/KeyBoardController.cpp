#include "sapch.h"
#include "KeyboardController.h"
#include "MyObjects/Player.h"
#include "GameState/GameState.h"



KeyboardController::KeyboardController(Player* player)
	:m_Player(player)
	{
		IsMouseClicked = true;
	}

KeyboardController::~KeyboardController()
{
	IsMouseClicked = false;
}

void KeyboardController::UpdateLocation(SDL_Event& e)
{
	
	const Uint8* state = SDL_GetKeyboardState(NULL);

	//if (state[SDL_SCANCODE_W] && !state[SDL_SCANCODE_S])
	//{
	//	w = true;		
	//	m_Player->MoveUp();
	//}	
	//
	//if (state[SDL_SCANCODE_A])
	//{
	//	a = true;
	//	m_Player->MoveLeft();
	//}	

	//if (state[SDL_SCANCODE_D])
	//{	
	//	d = true;
	//	m_Player->MoveRight();
	//}

	//if (!state[SDL_SCANCODE_D] && !state[SDL_SCANCODE_A])
	//{		
	//	//m_Player->SetXVelocity(0);
	//}
	//
	//if (state[SDL_SCANCODE_S] && !state[SDL_SCANCODE_W])
	//{
	//	s = true;
	//	m_Player->MoveDown();
	//}
	//if (!state[SDL_SCANCODE_S] && !state[SDL_SCANCODE_W])
	//{
	//	s = true;
	//	//m_Player->SetYVelocity(0);
	//}

	/*if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (!IsMouseClicked)
		{
			std::cout << "clieked controller " << IsMouseClicked << std::endl;
			std::cout << "FIREGUNTRUE~\n";

			m_Player->FireGun();
			IsMouseClicked = true;
		}
	}

	if (e.type == SDL_MOUSEBUTTONUP)
	{
		if (IsMouseClicked)
		{
			std::cout << "Unclickedcontroller~\n";
			IsMouseClicked = false;
		}		
	}*/
	
	if (state[SDL_SCANCODE_R])
	{
		if (!r)
		{
			m_Player->GetComponent<ProjectileComponent>().Reload();
			std::cout << "reloading!\n";
			r = true;
		}
		
	}

	if (!state[SDL_SCANCODE_R])
	{
		r = false;
	}

	if (state[SDL_SCANCODE_ESCAPE])
	{
		m_Player->Paused = true;
	}	
}