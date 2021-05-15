#include "Asteroid.h"

Asteroid::Asteroid()
{
	std::cout << "Asteroid!\n";

	m_ImageName = "D:/Dev/Asteroid_old/GameEngine/GameEngine/assets/asteroid.png";
	// x,y,w,h,sc,speed,vx,vy,
	InitComponents(0,0,32,32,1,3,0,1);	
}

Asteroid::Asteroid(int x, int y)
{
	std::cout << "Asteroid!\n";

	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/asteroid.png";
	InitComponents(x, y, 32, 32, 1, 3, 0, 1);
}

Asteroid::~Asteroid() {}



//void Asteroid::InitComponents()
//{
//	m_ComponentManager = std::make_unique<ComponentManager>();
//	m_ComponentManager->AddComponent<TransformComponent>(0,0, 32, 32, 1,3,0,1);
//	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
//	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
//	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
//}
//
//void Asteroid::InitComponents(int x, int y)
//{
//	m_ComponentManager = std::make_unique<ComponentManager>();
//	m_ComponentManager->AddComponent<TransformComponent>(x, y, 32, 32, 1, 3,0,1);
//	m_TransformComponent = &m_ComponentManager->GetComponent<TransformComponent>();
//	m_ComponentManager->AddComponent<TextureComponent>(m_ImageName.c_str(), m_TransformComponent);
//	m_TextureComponent = &m_ComponentManager->GetComponent<TextureComponent>();
//}


void Asteroid::Render()
{
	//SDL_RenderCopy(Game::renderer, objTexture, NULL, &m_DestRect);
}

void Asteroid::EventDispatch(SDL_Event& e)
{

}
