#pragma once
#include "Pawn.h"
#include "Vector2D.h"
#include "SDL.h"

#include "ECS/ComponentManager.h"
#define PI 3.14159265358979323846



class Player : public Pawn
{

public:	
	Player();
	Player(std::string imageFile, int x, int y);

	~Player();

	//void Update();		
	//float GetAngle(int x1, int y1, int x2, int y2);
	//void Rotate(SDL_Texture* texture, int x, int y, float angle);

	void InitComponents() override;
	void InitComponents(int x, int y) override;



private:

	/*TransformComponent* m_TransformComponent;
	TextureComponent* m_TextureComponent;
	std::unique_ptr<ComponentManager> m_ComponentManager;*/
	//SDL_Texture* objTexture;
	//SDL_Rect srcRect, destRect;
};

