#include "Player.h"



Player::Player()
{
	std::cout << "player!\n";

	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/ship.png";
	InitComponents();
}

Player::Player(std::string imageFile, int x, int y)
{
	std::cout << "player!\n";

	InitComponents();

	m_ImageName = "D:/Dev/Asteroid_old/GameEngine/GameEngine/assets/ship.png";

}

Player::~Player() {}

void Player::InitComponents()
{
	m_ComponentManager = std::make_unique<ComponentManager>();
	m_ComponentManager->AddComponent<TransformComponent>(0, 0, 32, 32, 4, 5);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
}

void Player::InitComponents(int x, int y)
{
	m_ComponentManager = std::make_unique<ComponentManager>();
	m_ComponentManager->AddComponent<TransformComponent>(x, y, 32, 32, 1, 5);
	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
}

//void Player::Update()
//{
//	//m_ComponentManager->GetComponent<TransformComponent>();
//	int mx, my;
//	SDL_GetMouseState(&mx, &my);
//
//	m_TransformComponent->Update();
//	m_TextureComponent->Update();	
//}



//float Player::GetAngle(int x1, int x2, int y1, int y2)
//{
//	float angle = -90 + atan2(y1 - y2, x1 - x2) * (180 / PI);
//	return angle >= 0 ? angle : 360 + angle;
//}

//void Player::Rotate(SDL_Texture* texture, int x, int y, float angle)
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
