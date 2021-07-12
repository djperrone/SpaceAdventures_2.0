#include "sapch.h"
#include "Player.h"

Player::Player(Character* mouseCursor, InputController* inputController)
	:m_MouseCursor(mouseCursor), m_InputController(inputController)
{
	//m_MouseCursor = mouseCursor;
	std::cout << "player!\n";

	m_ImageName = "assets/Spaceship.png";

	m_Team = Team::Friend;
	m_Tag = Tag::Player;
	
	InitComponents(350, 400, 32, 32, 3.5f, 90.0f, 4.0f, 0.0f, 0.0f, 5.0f, 1.0f);
	InitGun();
	InitController();
	m_PreviousPosition = m_TransformComponent->GetPositionVec();
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

bool Player::FireGun()
{
	return m_Gun->FireGun();
}

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

	//std::cout << "paused: " << Paused << std::endl;
	float dx = (m_MouseCursor->GetXPosition() - GetXPosition());
	float dy = (m_MouseCursor->GetYPosition() - GetYPosition());

	/*float dx = (m_MouseCursor->GetXPosition() + (m_MouseCursor->GetWidth() * m_MouseCursor->GetScale()) / 2 - GetXPosition() + (GetWidth() * GetScale() / 2));
	float dy = (m_MouseCursor->GetYPosition() + (m_MouseCursor->GetHeight() * m_MouseCursor->GetScale()) / 2 - GetYPosition() + (GetHeight() * GetScale() / 2));*/
	float angle;
	angle = atan2(dy, dx) * (180 / 3.146f);	

	//angle >= 0 ? angle : angle += 360;
	SetAngle(angle);

	//Vector2D oldPos = m_TransformComponent->GetPositionVec();
	//UpdateLocation();
	Vector2D currentPos = m_TransformComponent->GetPositionVec();

	if (currentPos.x < -15 || currentPos.x > dimensions.WIDTH + 15 - m_TransformComponent->GetWidth() * m_TransformComponent->GetScale() ||
		currentPos.y < -15 || currentPos.y > dimensions.HEIGHT + 15 - m_TransformComponent->GetHeight() * m_TransformComponent->GetScale())
	{
		m_TransformComponent->SetXPosition(m_PreviousPosition.x);
		m_TransformComponent->SetYPosition(m_PreviousPosition.y);
	}

	/*else if (currentPos.x > dimensions.WIDTH +15 - m_TransformComponent->GetWidth() * m_TransformComponent->GetScale())
	{
		m_TransformComponent->SetXPosition(m_PreviousPosition.x);
	}*/

	/*else if (currentPos.y < -15)
	{
		m_TransformComponent->SetYPosition(m_PreviousPosition.y);
	}

	else if (currentPos.y > dimensions.HEIGHT + 15 - m_TransformComponent->GetHeight() * m_TransformComponent->GetScale())
	{
		m_TransformComponent->SetYPosition(m_PreviousPosition.y);
	}*/
	else 
	{
		m_PreviousPosition = currentPos;

	}
	
	m_TextureComponent->Update();
	m_Gun->Update();
}

bool Player::Reload()
{
	std::cout << "relloading!\n";
	m_Gun->Reload();
	return true;
}

void Player::Pause()
{
	Paused = true;
}


void Player::InitController()
{
	m_InputController->BindAxisKeyMapping(SDL_SCANCODE_W, &Player::MoveUp, this);
	m_InputController->BindAxisKeyMapping(SDL_SCANCODE_A, &Player::MoveLeft, this);
	m_InputController->BindAxisKeyMapping(SDL_SCANCODE_S, &Player::MoveDown, this);
	m_InputController->BindAxisKeyMapping(SDL_SCANCODE_D, &Player::MoveRight, this);
	//m_InputController->BindAxisKeyMapping(SDL_SCANCODE_SPACE, &Player::FireGun, this);
	//m_InputController->BindAxisKeyMapping(SDL_SCANCODE_SPACE, &Player::FireGun, this);
	m_InputController->BindActionMapping(SDL_SCANCODE_SPACE, SDL_KEYDOWN, &Player::FireGun, this);

	m_InputController->BindAxisKeyMapping(SDL_SCANCODE_ESCAPE, &Player::Pause, this);

	m_InputController->BindActionMapping(SDL_BUTTON_LEFT, SDL_MOUSEBUTTONDOWN, &Player::FireGun, this);

	//m_InputController->BindActionKeyMapping(InputControlCodes::LEFT_MOUSE_BUTTON, SDL_MOUSEBUTTONDOWN, &Player::FireGun, this);
	//m_InputController->BindActionKeyMapping(MouseButton::Left, SDL_MOUSEBUTTONDOWN, &Player::FireGun, this);
	//m_InputController->BindActionKeyMapping(SDL_SCANCODE_R, SDL_KEYDOWN, &Player::Reload, this);

	// m_InputController->BindActionKeyMapping(SDL_BUTTON/KEY, INPUTEVENTTYPE, FUNCTION, THIS)
}
