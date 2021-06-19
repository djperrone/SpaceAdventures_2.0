#pragma once

#include <SDL.h>
#include "Math/Vector2d.h"
#include "ECS/ComponentManager.h"
#include "ECS/TransformComponent.h"
#include "ECS/TextureComponent.h"

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
	//GameObject();
	
	virtual ~GameObject() { }

	virtual void InitComponents() {}
	virtual void InitComponents(int x, int y) {}
	
	virtual void InitComponents(const char* fileName, float xPos, float yPos, int width, int height, float scale, float angle);

	virtual void Update() = 0;	

	std::string GetImageName() const;

	SDL_Rect& GetDestRect();	

	virtual float GetXPosition() const ;
	virtual float GetYPosition() const ;
	virtual void SetXPosition(float xPos);
	virtual void SetYPosition(float yPos);

	int GetWidth() const ;
	int GetHeight() const;
	void SetWidth(int width);
	void SetHeight(int height);
	

	float GetScale() const ;
	void SetScale(float scale);

	Vector2D GetPositionVec() const;

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
	std::unique_ptr<ComponentManager> m_ComponentManager;
	

private:
	
};

