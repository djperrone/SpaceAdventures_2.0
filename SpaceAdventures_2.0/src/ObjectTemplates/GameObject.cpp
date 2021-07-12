#include "sapch.h"
#include "GameObject.h"




void GameObject::InitComponents(const char* fileName, float xPos, float yPos, int width, int height, float scale, float angle)
{
	m_ComponentManager = std::make_unique<ComponentManager>();
	m_ComponentManager->AddComponent<TransformComponent>(xPos, yPos, width, height, scale, angle);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
	m_ComponentManager->AddComponent<TextureComponent>(fileName, m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
}

std::string GameObject::GetImageName() const { return m_TextureComponent->GetImageFileName(); }
SDL_Rect& GameObject::GetDestRect() { return m_TextureComponent->GetDestRect(); }

float GameObject::GetXPosition() const { return m_TransformComponent->GetXPosition(); }
float GameObject::GetYPosition() const { return m_TransformComponent->GetYPosition(); }
void GameObject::SetXPosition(float xPos) { m_TransformComponent->SetXPosition(xPos); }
void GameObject::SetYPosition(float yPos) { m_TransformComponent->SetYPosition(yPos); }

int GameObject::GetWidth() const { return m_TransformComponent->GetWidth(); }
int GameObject::GetHeight() const { return m_TransformComponent->GetHeight(); }
void GameObject::SetWidth(int width) { m_TransformComponent->SetWidth(width); }
void GameObject::SetHeight(int height) { m_TransformComponent->SetHeight(height); }


float GameObject::GetScale() const { return m_TransformComponent->GetScale(); }
void GameObject::SetScale(float scale) { m_TransformComponent->SetScale(scale); }

Vector2D GameObject::GetPositionVec() const { return m_TransformComponent->GetPositionVec(); }

float GameObject::GetAngle() const { return m_TransformComponent->GetAngle(); }
void GameObject::SetAngle(float angle) { m_TransformComponent->SetAngle(angle); }


