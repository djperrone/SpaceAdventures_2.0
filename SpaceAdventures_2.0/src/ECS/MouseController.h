//#pragma once
//#include "SDL.h"
//#include "MyObjects/Player.h"
//#include "ObjectTemplates/Actor.h"
//#include "SDL.h"
//class MouseController : public Actor
//{
//public:
//	MouseController(SDL_Event& event, Player* player)
//	{
//		m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/mouse_cursor.png";
//
//		SDL_GetMouseState(&m_XPosition, &m_YPosition);
//		SDL_ShowCursor(false);
//	}
//
//	void Tick()
//	{
//
//		SDL_GetMouseState(&m_XPosition, &m_YPosition);
//		m_TransformComponent->SetXPosition((float)m_XPosition);
//		m_TransformComponent->SetYPosition((float)m_YPosition);
//		//SDL_GetMouseState(&m_XPosition, &m_YPosition);
//
//		//std::cout << "mouse location: " << m_XPosition << ", " << m_YPosition << std::endl;
//
//	}
//	
//	void InitComponents() override
//	{
//		m_ComponentManager = std::make_unique<ComponentManager>();
//
//		m_ComponentManager->AddComponent<TransformComponent>(16, 16, 1);
//		m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
//
//		m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
//		m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
//	}
//
//private:
//
//	int m_XPosition, m_YPosition;
//};