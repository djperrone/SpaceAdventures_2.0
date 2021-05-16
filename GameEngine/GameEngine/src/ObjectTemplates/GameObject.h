#pragma once

#include "Vector3D.h"
#include "ECS/ComponentManager.h"
#include "SDL.h"

enum class Team
{
	None = 0,
	Friend,
	Enemy
};

class GameObject
{
public:
	//GameObject() {}	
	virtual ~GameObject() {}

	virtual void InitComponents() {}
	virtual void InitComponents(int x, int y) {}
	virtual void InitComponents(float xPos, float yPos, int width, int height, float scale, float speed, float xVel, float yVel, float health, float damage) {}
	//virtual void InitComponents(Vector2D position, int width, int height, float scale, float speed, Vector2D velocity, float health, float damage) {}
	//virtual void InitComponents(Vector2D position, Vector3D<int,int,float> dimensions, Vector3D<int, int, float> velocity, float health, float damage) {}
	//virtual void InitComponents(Vector2D&& position, Vector3D<int, int, float>&& dimensions, Vector3D<int, int, float>&& velocity, float health, float damage) {}



	virtual void Update() = 0;	

	inline const std::string& GetImageName() const { return m_ImageName; }	

	virtual inline SDL_Rect& GetDestRect() { return m_TextureComponent->GetDestRect(); }

	inline float GetXVelocity() const { return m_TransformComponent->GetXVelocity(); }
	inline float GetYVelocity() const { return m_TransformComponent->GetYVelocity(); }
	inline void SetXVelocity(float xVelocity) { m_TransformComponent->SetXVelocity(xVelocity); }
	inline void SetYVelocity(float yVelocity) { m_TransformComponent->SetYVelocity(yVelocity); }

	inline float GetXPosition() const { return m_TransformComponent->GetXPosition(); }
	inline float GetYPosition() const { return m_TransformComponent->GetYPosition(); }
	inline void SetXPosition(float xPos) { m_TransformComponent->SetXPosition(xPos); }
	inline void SetYPosition(float yPos) { m_TransformComponent->SetYPosition(yPos); }

	inline int GetWidth() const { return m_TransformComponent->GetWidth(); }
	inline int GetHeight() const { return m_TransformComponent->GetHeight(); }
	inline void SetWidth(int width) { m_TransformComponent->SetWidth(width); }
	inline void SetHeight(int height) { m_TransformComponent->SetHeight(height); }
	inline float GetSpeed() const { return m_TransformComponent->GetSpeed(); }
	inline float SetSpeed(float speed) { m_TransformComponent->SetSpeed(speed); }

	inline float GetScale() const { return m_TransformComponent->GetScale(); }
	inline float SetScale(float scale) { m_TransformComponent->SetScale(scale); }

	template <typename T>
	T& GetComponent()
	{
		return m_ComponentManager->GetComponent<T>();
	}

protected:	
	std::string m_ImageName;	
	TransformComponent* m_TransformComponent;
	TextureComponent* m_TextureComponent;
	ColliderComponent* m_ColliderComponent;
	std::unique_ptr<ComponentManager> m_ComponentManager;

private:
	
};

