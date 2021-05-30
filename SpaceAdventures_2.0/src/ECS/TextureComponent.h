#pragma once
#include "Component.h"
//#include "../TextureManager.h"
#include "SDL.H"
#include "TransformComponent.h"

class TextureComponent : public Component
{
	//SDL_Texture* m_Texture;
	const char* m_FileName;
	TransformComponent* m_Transform;
	SDL_Rect m_SrcRect, m_DestRect;


public:

	//static ComponentType GetStaticType() { return ComponentType::TextureComponent; }
	//ComponentType GetComponentType() const override { return GetStaticType(); }
	//ComponentType ComponentTypeID = ComponentType::TextureComponent;
	COMPONENT_CLASS_TYPE(TextureComponent)
	TextureComponent(const char* imageFile, TransformComponent* transform)
		:m_FileName(imageFile), m_Transform(transform)
	{
		m_SrcRect.h = m_Transform->GetHeight();
		m_SrcRect.w = m_Transform->GetWidth();		

		m_SrcRect.x = m_Transform->GetXPosition();
		m_SrcRect.y = m_Transform->GetYPosition();		

		m_DestRect.x = m_Transform->GetXPosition();
		m_DestRect.y = m_Transform->GetYPosition();
		m_DestRect.w = m_SrcRect.w * m_Transform->GetScale();
		m_DestRect.h = m_SrcRect.h * m_Transform->GetScale();
	}

	void Init() override
	{
		//transform = &entity->getComponent<TransformComponent>();


		
	}

	virtual void Update() override
	{		
		
		m_SrcRect.x = m_Transform->GetXPosition();
		m_SrcRect.y = m_Transform->GetYPosition();

		//m_SrcRect.y = m_Transform->height;
		m_DestRect.x = m_Transform->GetXPosition();
		m_DestRect.y = m_Transform->GetYPosition();
		m_DestRect.w = m_SrcRect.w * m_Transform->GetScale();
		m_DestRect.h = m_SrcRect.h * m_Transform->GetScale();
	}

	inline SDL_Rect& GetDestRect() { return m_DestRect; }


};