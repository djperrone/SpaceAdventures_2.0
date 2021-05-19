#pragma once
#include "SDL.h"
#include "ObjectTemplates/Actor.h"
#include "MyObjects/Player.h"

class MouseCursor : public Actor
{
public:

	MouseCursor(SDL_Event& event)
			{
		//int x, y;
				SDL_ShowCursor(false);
				m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/mouse_cursor.png";		
				InitComponents();
				SDL_GetMouseState(&m_XPosition, &m_YPosition);
				SetXPosition(m_XPosition);
				SetYPosition(m_YPosition);
			}

	void Tick()
	{
		SDL_GetMouseState(&m_XPosition, &m_YPosition);
		SDL_GetMouseState(&m_XPosition, &m_YPosition);
		SetXPosition(m_XPosition);
		SetYPosition(m_YPosition);
		//
		m_TransformComponent->Update();
		m_TextureComponent->Update();
		std::cout << "mouse location: " << m_XPosition << ", " << m_YPosition << std::endl;
	}


	void InitComponents() override
			{
				m_ComponentManager = std::make_unique<ComponentManager>();
		
				m_ComponentManager->AddComponent<TransformComponent>(16, 16, 1);
				m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
		
				m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
				m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
			}

	//inline int GetXPosition()const{ return m_XPosition; }
	//inline int GetYPosition()const{ return m_YPosition; }


private:
	int m_XPosition, m_YPosition;
};