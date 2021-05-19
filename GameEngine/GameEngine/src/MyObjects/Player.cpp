#include "Player.h"
#include <cmath>



Player::Player(MouseCursor* mouseCursor)
	:m_MouseCursor(mouseCursor)
{
	//m_MouseCursor = mouseCursor;
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
	InitComponents(100, 100, 32, 32, 3.5f, 1.0f, 4.0f, 0.0f, 0.0f, 5.0f, 1.0f);

}





Player::Player(std::string imageFile, int x, int y)
{
	m_Team = Team::Friend;

	std::cout << "player!\n";
	m_ImageName = "D:/Dev/Asteroid_old/GameEngine/GameEngine/assets/Spaceship.png";

	//InitComponents();
	// x,y,w,h,sc,speed,vx,vy,health, damage
	InitComponents(0, 0, 32, 32, 1.0f, 0.0f, 3.0f, 0.0f, 0.0f, 3.0f, 1.0f);
}

Player::~Player() { std::cout << "destroyed player\n"; }

void Player::Update()
{
	//std::cout <<"player gun size "<< m_Gun->GetProjectileList().size() << std::endl;;

	//SetAngle(GetAngle() + 1);
	//SetAngle(180);
	//int x = 400;
	//int y = 300;
	float dx = (float)(m_MouseCursor->GetXPosition()- GetXPosition());
	float dy = (float)(m_MouseCursor->GetYPosition()-GetYPosition()) ;

	//float dx = (float)(GetXPosition()- m_MouseCursor->GetXPosition());
	//float dy = (float)(GetYPosition()- m_MouseCursor->GetYPosition());



	//int dx = (GetXPosition()-x);
	//int dy = (GetYPosition());

	//float angle = ((atan2(-dy, -dx)) * (180.0f / 3.416f));

	//float angle = 270 + atan2(dy, dx) * (180 / PI);


	float angle = -270 + atan2(dy, dx) * (180 / PI);
	//angle >= 0 ? angle : 360 + angle;


	SetAngle(angle);


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