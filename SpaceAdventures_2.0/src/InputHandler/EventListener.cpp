#include "sapch.h"
#include "EventListener.h"
#include "InputHandler.h"

SDL_Event EventListener::Event;
bool EventListener::IsMouseClicked;
bool EventListener::IsMouseRepeating;

//InputHandler* inputHandler = new InputHandler();

void EventListener::PollEvents()
{
	//inputHandler->Update();
	while (SDL_PollEvent(&EventListener::Event))
	{
		if (EventListener::IsMouseClicked)
		{
			if (EventListener::Event.type != SDL_MOUSEBUTTONUP)
			{
				EventListener::IsMouseRepeating = true;
			}
			else
			{
				EventListener::IsMouseRepeating = false;
			}
		}		
		switch (EventListener::Event.type)
		{
		case SDL_QUIT:
			Game::isRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN: 
			
			EventListener::IsMouseClicked = true;
			if (!EventListener::IsMouseRepeating)
			{
				std::cout << "Mouse Down EventLister - \n";

			}
			
			break;
		case SDL_MOUSEBUTTONUP:
			EventListener::IsMouseClicked = false;
			EventListener::IsMouseRepeating = false;

			std::cout << "Mouse Up EventLister\n";
			break;
		case SDL_KEYDOWN:

			if (EventListener::Event.key.repeat == 0)
			{
				std::cout << "KeyDown EventLister\n";
				EventListener::Event.key.keysym.scancode == SDL_SCANCODE_R ? std::cout << "R PRESSED!\n" : std::cout << "";
				//break;
			}
			else
			{
				//std::cout << "KeyRepeat EventLister\n";
				//break;
			}

			break;
		case SDL_KEYUP:
			std::cout << "KeyUp EventLister\n";
			break;
		//case 

			//break;
		default:
			break;
		}
	}
}