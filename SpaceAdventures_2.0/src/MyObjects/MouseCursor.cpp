#include "sapch.h"
#include "MouseCursor.h"

#include "SDL.h"

MouseCursor::MouseCursor()
{

	m_ImageName = "assets/mouse_cursor.png";
	InitComponents();
	SDL_GetMouseState(&m_XPosition, &m_YPosition);
	SetXPosition(static_cast<float>(m_XPosition));
	SetYPosition(static_cast<float>(m_YPosition));
}

void MouseCursor::Update()
{
	SDL_GetMouseState(&m_XPosition, &m_YPosition);
	SetXPosition(static_cast<float>(m_XPosition));
	SetYPosition(static_cast<float>(m_YPosition));
	//UpdateLocation();
	m_TextureComponent->Update();
}


void MouseCursor::InitComponents() 
{
	m_ComponentManager = std::make_unique<ComponentManager>();

	m_ComponentManager->AddComponent<TransformComponent>(0.0f,0.0f,16, 16, 1);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();

	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
}