#include "sapch.h"
#include "Player.h"

Player::Player(Character* mouseCursor)
	:m_MouseCursor(mouseCursor)
{
	//m_MouseCursor = mouseCursor;
	std::cout << "player!\n";

	m_ImageName = "assets/Spaceship.png";

	m_Team = Team::Friend;
	m_Tag = Tag::Player;
	
	InitComponents(250, 250, 32, 32, 3.5f, 0.0f, 4.0f, 0.0f, 0.0f, 5.0f, 1.0f);
	InitGun();
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

void Player::MoveUp()
{
	//SetYVelocity(-1);
	SetYPosition(GetYPosition() + -1 * GetSpeed());

}

void Player::MoveDown()
{
	//SetYVelocity(1);
	SetYPosition(GetYPosition() + 1 * GetSpeed());


}

void Player::MoveLeft()
{
	//SetXVelocity(-1);
	SetXPosition(GetXPosition() + -1 * GetSpeed());

}

void Player::MoveRight()
{
	//SetXVelocity(1);
	SetXPosition(GetXPosition() + 1 * GetSpeed());

}

void Player::Update()
{
	
	float dx = (m_MouseCursor->GetXPosition() - GetXPosition());
	float dy = (m_MouseCursor->GetYPosition() - GetYPosition());

	/*float dx = (m_MouseCursor->GetXPosition() + (m_MouseCursor->GetWidth() * m_MouseCursor->GetScale()) / 2 - GetXPosition() + (GetWidth() * GetScale() / 2));
	float dy = (m_MouseCursor->GetYPosition() + (m_MouseCursor->GetHeight() * m_MouseCursor->GetScale()) / 2 - GetYPosition() + (GetHeight() * GetScale() / 2));*/
	float angle;
	angle = atan2(dy, dx) * (180 / 3.146f);	

	//angle >= 0 ? angle : angle += 360;
	SetAngle(angle);

	Vector2D oldPos = m_TransformComponent->GetPositionVec();
	UpdateLocation();
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
	m_Gun->Update();
}