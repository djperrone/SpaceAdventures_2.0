#pragma once
#include "Component.h"
#include "SDL.H"


class TransformComponent;

class TextureComponent : public Component
{	
public:
	COMPONENT_CLASS_TYPE(TextureComponent)
	TextureComponent(const char* imageFile, TransformComponent* transform);
	virtual void Init() override;
	virtual void Update() override;
	inline SDL_Rect& GetDestRect() { return m_DestRect; }

private:
	const char* m_FileName;
	TransformComponent* m_Transform;
	SDL_Rect m_SrcRect, m_DestRect;
};