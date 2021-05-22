#pragma once
#include "GameObject.h"
#include "ECS/ComponentManager.h"
#include "ECS/ColliderComponent.h"
#include "ECS/CombatComponent.h"
#define PI 3.14159265358979323846

class Actor : public GameObject
{

public:
	Actor();
	Actor(int x, int y);
	Actor(const std::string& texturesheet, int x, int y);
	virtual void InitComponents(int x, int y) override;


	virtual ~Actor();

	virtual void Update() override;	
	virtual void InitComponents() override;
	//virtual void InitComponents(float xPos, float yPos, float rotation, int width, int height, float scale, float speed, float xVel, float yVel, float health, float damage) override;
	//virtual void InitComponents(float xPos, float yPos, int width, int height, float scale, float speed, float xVel, float yVel, float health, float damage) override;
	//virtual void InitComponents(float xPos, float yPos, int width, int height, float scale,float angle, float speed, float xVel, float yVel, float health, float damage) override;
	void InitComponents(int xPos, int yPos, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage) override;

	// void InitComponents(float xPos, float yPos, float direction, int width, int height, float scale, float angle, float speed, float xVel, float yVel, float health, float damage) override;
	//virtual void InitComponents(float xPos, float yPos, float rotation, int width, int height, float scale, float speed, float xVel, float yVel, float health, float damage);


	//virtual void InitComponents(Vector2D position, Vector3D<int, int, float> dimensions, Vector3D<int, int, float> velocity, float health, float damage) override;
	//virtual void InitComponents(Vector2D&& position, Vector3D<int, int, float>&& dimensions, Vector3D<int, int, float>&& velocity, float health, float damage) override;


	//virtual void InitComponents(const std::string& texturesheet, int x, int y, float width, float height, float scale, float speed) override;

	//inline bool IsCollidable() const { return collidable; }
	
	float GetLeftBound() const;	
	float GetRightBound()const;
	float GetUpperBound()const;
	float GetLowerBound()const;
	
	inline float GetHealth() const { return m_CombatComponent->GetHealth(); }
	inline float GetDamage() const { return m_CombatComponent->GetDamage(); }

	inline void TakeDamage(float damage) { m_CombatComponent->TakeDamage(damage); }
	inline void Attack(Actor* actor) { m_CombatComponent->Attack(actor); } 
	inline bool IsAlive() const { return GetHealth() > 0; }

	inline Team GetTeam()const { return m_Team; }

	inline Tag GetTag() const { return m_Tag; }

	// center w = GetSDLRec().w * scale / 2
	// center y = GetSDLrec().h * scale / 2




protected:

	CombatComponent* m_CombatComponent;
	Team m_Team = Team::None;
	Tag m_Tag = Tag::None;
	//bool collidable;

	//float m_Health;

private:
	//collision component
	

};

