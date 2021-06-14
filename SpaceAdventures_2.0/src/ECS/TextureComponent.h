#pragma once
#include "Component.h"


class TransformComponent;

class TextureComponent : public Component
{	
public:
	COMPONENT_CLASS_TYPE(TextureComponent)
	TextureComponent(const std::string& imageFile, TransformComponent* transform);
	virtual void Init() override;
	virtual void Update() override;
	inline SDL_Rect& GetDestRect() { return m_DestRect; }
	inline std::string GetImageFileName() const { return m_FileName; }

private:
	std::string m_FileName;
	TransformComponent* m_Transform;
	SDL_Rect m_SrcRect, m_DestRect;
};