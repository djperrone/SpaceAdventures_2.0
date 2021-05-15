#include "Player.h"



Player::Player()
{
	std::cout << "player!\n";

	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Spaceship.png";

	team = Team::Friend;
	// x,y,w,h,sc,speed,vx,vy,health, damage

	InitComponents(100, 100, 32, 32, 4, 5, 0, 0, 5, 1);
	//InitComponents();
}

Player::Player(std::string imageFile, int x, int y)
{
	std::cout << "player!\n";
	m_ImageName = "D:/Dev/Asteroid_old/GameEngine/GameEngine/assets/Spaceship.png";

	//InitComponents();
	// x,y,w,h,sc,speed,vx,vy,health, damage
	InitComponents(0, 0, 32, 32, 1, 3, 0, 1, 3, 1);


}

Player::~Player() {}

//void Player::InitComponents()
//{
//	m_ComponentManager = std::make_unique<ComponentManager>();
//	m_ComponentManager->AddComponent<TransformComponent>(0, 0, 32, 32, 4, 5);
//
//	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
//	m_ComponentManager->AddComponent<ColliderComponent>(m_TransformComponent);
//
//	m_ComponentManager->AddComponent<CombatComponent>();
//	m_CombatComponent = &m_ComponentManager->GetComponent<CombatComponent>();
//
//	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
//	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
//
//}
//
//void Player::InitComponents(int x, int y)
//{
//	m_ComponentManager = std::make_unique<ComponentManager>();
//	m_ComponentManager->AddComponent<TransformComponent>(x, y, 32, 32, 1, 5);
//	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
//	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
//	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
//}

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
