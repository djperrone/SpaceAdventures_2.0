#pragma once
#include "SDL.h"
#include "ObjectTemplates/Actor.h"


class ReloadIcon : public Actor
{
public:

	ReloadIcon()
	{		
		m_ImageName = "assets/Reload_icon.png";
		InitComponents();	
	}

	void Tick()
	{
	
		m_TransformComponent->Update();
		m_TextureComponent->Update();
		
	}


	void InitComponents() override
	{
		m_ComponentManager = std::make_unique<ComponentManager>();

		m_ComponentManager->AddComponent<TransformComponent>(192, 64, 1,500,500);
		m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();

		m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
		m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
	}

private:
	int m_XPosition, m_YPosition;
};