
#include "sapch.h"
#include "GameObject.h"



std::string GameObject::GetImageName() const { return m_ImageName; }
SDL_Rect& GameObject::GetDestRect() { return m_TextureComponent->GetDestRect(); }

float GameObject::GetXVelocity() const { return m_TransformComponent->GetXVelocity(); }
float GameObject::GetYVelocity() const { return m_TransformComponent->GetYVelocity(); }
void GameObject::SetXVelocity(float xVelocity) { m_TransformComponent->SetXVelocity(xVelocity); }
void GameObject::SetYVelocity(float yVelocity) { m_TransformComponent->SetYVelocity(yVelocity); }

float GameObject::GetXPosition() const { return m_TransformComponent->GetXPosition(); }
float GameObject::GetYPosition() const { return m_TransformComponent->GetYPosition(); }
void GameObject::SetXPosition(float xPos) { m_TransformComponent->SetXPosition(xPos); }
void GameObject::SetYPosition(float yPos) { m_TransformComponent->SetYPosition(yPos); }

int GameObject::GetWidth() const { return m_TransformComponent->GetWidth(); }
int GameObject::GetHeight() const { return m_TransformComponent->GetHeight(); }
void GameObject::SetWidth(int width) { m_TransformComponent->SetWidth(width); }
void GameObject::SetHeight(int height) { m_TransformComponent->SetHeight(height); }
float GameObject::GetSpeed() const { return m_TransformComponent->GetSpeed(); }
void GameObject::SetSpeed(float speed) { m_TransformComponent->SetSpeed(speed); }

float GameObject::GetScale() const { return m_TransformComponent->GetScale(); }
void GameObject::SetScale(float scale) { m_TransformComponent->SetScale(scale); }

Vector2D GameObject::GetPositionVec() const { return m_TransformComponent->GetPositionVec(); }
Vector2D GameObject::GetVelocityVec() const { return m_TransformComponent->GetVelocityVec(); }

float GameObject::GetDirection() const { return m_TransformComponent->GetDirection(); }

float GameObject::GetAngle() const { return m_TransformComponent->GetAngle(); }
void GameObject::SetAngle(float angle) { m_TransformComponent->SetAngle(angle); }
