#include "sapch.h"
#include "TextureComponent.h"
#include "TransformComponent.h"

TextureComponent::TextureComponent(const std::string& imageFile, TransformComponent* transform)
	:m_FileName(imageFile), m_Transform(transform)
{
	Init();
}

void TextureComponent::Init()
{
	m_SrcRect.h = m_Transform->GetHeight();
	m_SrcRect.w = m_Transform->GetWidth();

	m_SrcRect.x = static_cast<int>(m_Transform->GetXPosition());
	m_SrcRect.y = static_cast<int>(m_Transform->GetYPosition());

	m_DestRect.x = static_cast<int>(m_Transform->GetXPosition());
	m_DestRect.y = static_cast<int>(m_Transform->GetYPosition());
	m_DestRect.w = static_cast<int>(m_SrcRect.w * m_Transform->GetScale());
	m_DestRect.h = static_cast<int>(m_SrcRect.h * m_Transform->GetScale());
}

void TextureComponent::Update()
{
	m_SrcRect.x = static_cast<int>(m_Transform->GetXPosition());
	m_SrcRect.y = static_cast<int>(m_Transform->GetYPosition());

	m_DestRect.x = static_cast<int>(m_Transform->GetXPosition());
	m_DestRect.y = static_cast<int>(m_Transform->GetYPosition());
	m_DestRect.w = static_cast<int>(m_SrcRect.w * m_Transform->GetScale());
	m_DestRect.h = static_cast<int>(m_SrcRect.h * m_Transform->GetScale());
}

