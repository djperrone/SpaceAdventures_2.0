#pragma once

#include <SDL.h>



#include "Vector2D.h"
#include "ECS/ComponentManager.h"
#include "ECS/TransformComponent.h"
#include "ECS/TextureComponent.h"
#include "ECS/ColliderComponent.h"
#include "ECS/CombatComponent.h"


enum class Tag
{
	None = 0,
	Asteroid,
	Ship,
	Player
};

enum class Team
{
	None = 0,
	Friend,
	Enemy
};

class GameObject
{
public:
	GameObject()
	:m_ColliderComponent(nullptr),m_ComponentManager(nullptr),m_TextureComponent(nullptr),m_TransformComponent(nullptr){}	
	virtual ~GameObject() { }

	virtual void InitComponents() {}
	virtual void InitComponents(int x, int y) {}
	
	virtual void InitComponents(int xPos, int yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage) {}

	virtual void Update() = 0;	

	std::string GetImageName() const;

	SDL_Rect& GetDestRect();

	float GetXVelocity() const;
	float GetYVelocity() const;
	void SetXVelocity(float xVelocity);
	void SetYVelocity(float yVelocity);

	virtual float GetXPosition() const ;
	virtual float GetYPosition() const ;
	virtual void SetXPosition(float xPos);
	virtual void SetYPosition(float yPos);

	int GetWidth() const ;
	int GetHeight() const;
	void SetWidth(int width);
	void SetHeight(int height);
	float GetSpeed() const;
	void SetSpeed(float speed);

	float GetScale() const ;
	void SetScale(float scale);

	Vector2D GetPositionVec() const;
	Vector2D GetVelocityVec() const;

	float GetDirection() const;

	float GetAngle() const;
	void SetAngle(float angle);

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

