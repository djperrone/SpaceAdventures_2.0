#pragma once
#include "SDL.h"
#include "ObjectTemplates/Actor.h"


class ReloadIcon : public Actor
{
public:

	ReloadIcon()
	{
		//int x, y;
		//SDL_ShowCursor(false);
		m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Reload_icon.png";
		InitComponents();
		//SDL_GetMouseState(&m_XPosition, &m_YPosition);
		//SetXPosition(400);
		//SetYPosition(400);
	}

	void Tick()
	{
		//SDL_GetMouseState(&m_XPosition, &m_YPosition);
		//SDL_GetMouseState(&m_XPosition, &m_YPosition);
		//SetXPosition(m_XPosition);
		//SetYPosition(m_YPosition);
		//
		m_TransformComponent->Update();
		m_TextureComponent->Update();
		//std::cout << "mouse location: " << m_XPosition << ", " << m_YPosition << std::endl;
	}


	void InitComponents() override
	{
		m_ComponentManager = std::make_unique<ComponentManager>();

		m_ComponentManager->AddComponent<TransformComponent>(192, 64, 1,500,500);
		m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();

		m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
		m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
	}

	//inline int GetXPosition()const{ return m_XPosition; }
	//inline int GetYPosition()const{ return m_YPosition; }


private:
	int m_XPosition, m_YPosition;
};