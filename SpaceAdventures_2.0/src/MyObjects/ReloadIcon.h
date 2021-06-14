#pragma once

#include "ObjectTemplates/Character.h"

class ReloadIcon : public Character
{
public:

	ReloadIcon()
	{		
		m_ImageName = "assets/Reload_icon.png";
		InitComponents();	
	}

	void InitComponents() override
	{
		m_ComponentManager = std::make_unique<ComponentManager>();

		m_ComponentManager->AddComponent<TransformComponent>(500, 500, 192, 64, 1);
		m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();

		m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
		m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
	}

	virtual void Update() override
	{
		m_TextureComponent->Update();
	}

private:
	int m_XPosition, m_YPosition;
};