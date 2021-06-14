#pragma once
class GameObject;
class Asteroid;
class Actor;
class Character;
class Vector2i;

class CollisionManager
{
public:
	CollisionManager(std::list<std::shared_ptr<Character>>* objList, std::list<std::unique_ptr<Asteroid>>* asteroidList);
	CollisionManager();

	void Tick();
	bool IsColliding(Character* current, Character* other);
	bool IsColliding(Actor* current, Vector2i pos);
	void HandleCollisionEvent(Character* current, Character* other);
	bool IsOnSameTeam(Character* current, Character* other);

protected:
	
private:
	std::list<std::shared_ptr<Character>>* m_ObjectList;
	std::list<std::unique_ptr<Asteroid>>* m_AsteroidList;	
};

