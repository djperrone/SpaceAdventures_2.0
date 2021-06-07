#include "sapch.h"
#include "KeyboardController.h"
#include "MyObjects/Player.h"

KeyboardController::KeyboardController(Player* player)
	:m_Player(player) {}

void KeyboardController::UpdateLocation(SDL_Event& e)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_W] && !state[SDL_SCANCODE_S])
	{
		w = true;		
		m_Player->SetYVelocity(-1);
	}	
	
	if (state[SDL_SCANCODE_A] && !state[SDL_SCANCODE_D])
	{
		a = true;
		m_Player->SetXVelocity(-1);
	}	

	if (state[SDL_SCANCODE_D] && !state[SDL_SCANCODE_A])
	{	
		d = true;
		m_Player->SetXVelocity(1);
	}

	if (!state[SDL_SCANCODE_D] && !state[SDL_SCANCODE_A])
	{		
		m_Player->SetXVelocity(0);
	}
	
	if (state[SDL_SCANCODE_S] && !state[SDL_SCANCODE_W])
	{
		s = true;
		m_Player->SetYVelocity(1);
	}
	if (!state[SDL_SCANCODE_S] && !state[SDL_SCANCODE_W])
	{
		s = true;
		m_Player->SetYVelocity(0);
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
		SDL_Quit();
		exit(0);
	}

	
						
					/*case SDLK_w:
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

						s = false;*/















	//else if()

	//			case SDLK_r:
	//				//if(!m_Player->GetComponent<ProjectileComponent>().reloading)
	//				m_Player->GetComponent<ProjectileComponent>().Reload();
	//			default:
	//				break;
	//			}
	//		}

	//		if (e.type == SDL_KEYUP)
	//		{
	//			switch (e.key.keysym.sym)
	//			{
	//			case SDLK_r:
	//				break;
	//			case SDLK_w:
	//				if (s == true)
	//					m_Player->SetYVelocity(1);
	//				else
	//					m_Player->SetYVelocity(0);
	//				w = false;

	//				break;
	//			case SDLK_a:

	//				if (d == true)
	//					m_Player->SetXVelocity(1);
	//				else
	//					m_Player->SetXVelocity(0);
	//				a = false;

	//				break;

	//			case SDLK_d:

	//				if (a == true)
	//					m_Player->SetXVelocity(-1);
	//				else
	//					m_Player->SetXVelocity(0);

	//				d = false;

	//				break;
	//			case SDLK_s:
	//				if (w == true)
	//					m_Player->SetYVelocity(-1);

	//				else
	//					m_Player->SetYVelocity(0);

	//				s = false;

	//				break;
	//			case SDLK_ESCAPE:
	//				//isRunning = false;
	//				SDL_Quit();
	//				exit(0);
	//			default:
	//				break;
	//			}
	//		}


	//		if (e.type == SDL_MOUSEBUTTONDOWN)
	//		{
	//			if (!clicked)
	//			{
	//				clicked = true;
	//				std::cout << "clicked~\n";

	//				m_Player->FireGun();
	//			}

	//		}

	//		if (e.type == SDL_MOUSEBUTTONUP)
	//		{
	//			//std::cout << "Unclicked~\n";
	//			clicked = false;
	//		}

		

		//if (e.type == SDL_KEYDOWN)
		//{
		//	switch (e.key.keysym.sym)
		//	{
		//	case SDLK_w:
		//		w = true;
		//		//m_Player->GetComponent<TransformComponent>()->velocity.y = -1;
		//		m_Player->SetYVelocity(-1);
		//		break;
		//	case SDLK_a:
		//		a = true;
		//		m_Player->SetXVelocity(-1);
		//		break;
		//	case SDLK_d:
		//		d = true;
		//		m_Player->SetXVelocity(1);
		//		break;
		//	case SDLK_s:
		//		s = true;
		//		m_Player->SetYVelocity(1);
		//		break;
		//	case SDLK_r:
		//		//if(!m_Player->GetComponent<ProjectileComponent>().reloading)
		//		m_Player->GetComponent<ProjectileComponent>().Reload();
		//	default:
		//		break;
		//	}
		//}

		//if (e.type == SDL_KEYUP)
		//{
		//	switch (e.key.keysym.sym)
		//	{
		//	case SDLK_r:
		//		break;
		//	case SDLK_w:
		//		if (s == true)
		//			m_Player->SetYVelocity(1);
		//		else
		//			m_Player->SetYVelocity(0);
		//		w = false;

		//		break;
		//	case SDLK_a:

		//		if (d == true)
		//			m_Player->SetXVelocity(1);
		//		else
		//			m_Player->SetXVelocity(0);
		//		a = false;

		//		break;

		//	case SDLK_d:

		//		if (a == true)
		//			m_Player->SetXVelocity(-1);
		//		else
		//			m_Player->SetXVelocity(0);

		//		d = false;

		//		break;
		//	case SDLK_s:
		//		if (w == true)
		//			m_Player->SetYVelocity(-1);

		//		else
		//			m_Player->SetYVelocity(0);

		//		s = false;

		//		break;
		//	case SDLK_ESCAPE:
		//		//isRunning = false;
		//		SDL_Quit();
		//		exit(0);
		//	default:
		//		break;
		//	}
		//}
	

		//if (e.type == SDL_MOUSEBUTTONDOWN)
		//{
		//	if (!clicked)
		//	{
		//		clicked = true;
		//		std::cout << "clicked~\n";

		//		m_Player->FireGun();
		//	}

		//}

		//if (e.type == SDL_MOUSEBUTTONUP)
		//{
		//	//std::cout << "Unclicked~\n";
		//	clicked = false;
		//}
	
}