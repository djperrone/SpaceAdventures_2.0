#include "Player.h"



Player::Player()
{
	std::cout << "player!\n";

	m_ImageName = "D:/Dev/SpaceAdventures_2.0/GameEngine/GameEngine/assets/Spaceship.png";

	m_Team = Team::Friend;
	// x,y,w,h,sc,speed,vx,vy,health, damage

	/*Vector2D position{ 100,100 };
	Vector3D<int, int, float> position{ 100,100,1.0f };
	Vector3D<int, int, float> dimensions{ 32,32,4.0f };
	Vector3D<int,int,float> velocity{ 100,100,1.0f };*/

	//InitComponents(position, dimensions, velocity, 5.0f, 1.0f);
	//InitComponents();
	InitComponents(100, 100, 32, 32, 4, 5, 0, 0, 5, 1);

}



Player::Player(std::string imageFile, int x, int y)
{
	m_Team = Team::Friend;

	std::cout << "player!\n";
	m_ImageName = "D:/Dev/Asteroid_old/GameEngine/GameEngine/assets/Spaceship.png";

	//InitComponents();
	// x,y,w,h,sc,speed,vx,vy,health, damage
	InitComponents(0, 0, 32, 32, 1, 3, 0, 0, 3, 1);
}

Player::~Player() { std::cout << "destroyed player\n"; }

void Player::Update()
{
	//std::cout <<"player gun size "<< m_Gun->GetProjectileList().size() << std::endl;;

	Vector2D oldPos = m_TransformComponent->GetPositionVec();
	m_TransformComponent->Update();
	Vector2D currentPos = m_TransformComponent->GetPositionVec();

	if (currentPos.x < -15)
	{
		m_TransformComponent->SetXPosition(oldPos.x);		
	}

	if (currentPos.x > dimensions.WIDTH +15 - m_TransformComponent->GetWidth() * m_TransformComponent->GetScale())
	{
		m_TransformComponent->SetXPosition(oldPos.x);

	}

	if (currentPos.y < -15)
	{
		m_TransformComponent->SetYPosition(oldPos.y);
	}

	if (currentPos.y > dimensions.HEIGHT + 15 - m_TransformComponent->GetHeight() * m_TransformComponent->GetScale())
	{
		m_TransformComponent->SetYPosition(oldPos.y);

	}


	m_TextureComponent->Update();
	
}