#include "KeyboardController.h"

KeyboardController::KeyboardController(Player* player)
	:m_Player(player) {}

void KeyboardController::UpdateLocation(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			w = true;
			//m_Player->GetComponent<TransformComponent>()->velocity.y = -1;
			m_Player->SetYVelocity(-1);
			break;
		case SDLK_a:
			a = true;
			m_Player->SetXVelocity(-1);
			break;
		case SDLK_d:
			d = true;
			m_Player->SetXVelocity(1);
			break;
		case SDLK_s:
			s = true;
			m_Player->SetYVelocity(1);
			break;
		default:
			break;
		}
	}

	if (e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			if (s == true)
				m_Player->SetYVelocity(1);
			else
				m_Player->SetYVelocity(0);
			w = false;

			break;
		case SDLK_a:

			if (d == true)
				m_Player->SetXVelocity(1);
			else
				m_Player->SetXVelocity(0);
			a = false;

			break;

		case SDLK_d:

			if (a == true)
				m_Player->SetXVelocity(-1);
			else
				m_Player->SetXVelocity(0);

			d = false;

			break;
		case SDLK_s:
			if (w == true)
				m_Player->SetYVelocity(-1);

			else
				m_Player->SetYVelocity(0);

			s = false;

			break;
		case SDLK_ESCAPE:
			//Game::isRunning = false;
		default:
			break;
		}
	}

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (!clicked)
		{
			clicked = true;
			std::cout << "clicked~\n";

			m_Player->FireGun();
		}
		
	}

	if (e.type == SDL_MOUSEBUTTONUP)
	{
		//std::cout << "Unclicked~\n";
		clicked = false;
	}

}