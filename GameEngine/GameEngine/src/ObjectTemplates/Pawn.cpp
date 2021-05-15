#include "Pawn.h"



Pawn::Pawn()
{
	std::cout << "Pawn!\n";

	//InitComponents();

	m_ImageName = "D:/Dev/Asteroid_old/GameEngine/GameEngine/assets/ship.png";
	
}

Pawn::Pawn(const std::string& texturesheet, int x, int y)
{	
	
}


Pawn::~Pawn() {}

void Pawn::InitComponents()
{
	m_ComponentManager = std::make_unique<ComponentManager>();
	m_ComponentManager->AddComponent<TransformComponent>(0, 0, 32, 32, 4, 5);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();

}

void Pawn::InitComponents(float xPos, float yPos, int width, int height, float scale, float speed, float xVel, float yVel, float health, float damage)
{
	m_ComponentManager = std::make_unique<ComponentManager>();

	m_ComponentManager->AddComponent<TransformComponent>(xPos, yPos, width, height, scale, speed, xVel, yVel);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();

	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();

	m_ComponentManager->AddComponent<ColliderComponent>(m_TransformComponent);
	m_ColliderComponent = &m_ComponentManager->GetComponent<ColliderComponent>();

	m_ComponentManager->AddComponent<CombatComponent>(health, damage);
	m_CombatComponent = &m_ComponentManager->GetComponent<CombatComponent>();
}

void Pawn::Update()
{
	//m_ComponentManager->GetComponent<TransformComponent>();
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	m_TransformComponent->Update();
	m_TextureComponent->Update();

	//std::cout <<"col "<< IsCollidable() << std::endl;
	
}


//
//float Pawn::GetAngle(int x1, int x2, int y1, int y2)
//{
//	float angle = -90 + atan2(y1 - y2, x1 - x2) * (180 / PI);
//	return angle >= 0 ? angle : 360 + angle;
//}

//void Pawn::Rotate(SDL_Texture* texture, int x, int y, float angle)
//{
//	SDL_Rect dstRect;
//
//	dstRect.x = x;
//	dstRect.y = y;
//	SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
//	dstRect.x -= (dstRect.w / 2);
//	dstRect.y -= (dstRect.h / 2);
//
//	SDL_RenderCopyEx(Game::renderer, texture, NULL, &dstRect, angle, NULL, SDL_FLIP_NONE);
//}
