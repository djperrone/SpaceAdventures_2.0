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
	std::cout << "player!\n";
	m_ImageName = "D:/Dev/Asteroid_old/GameEngine/GameEngine/assets/Spaceship.png";

	//InitComponents();
	// x,y,w,h,sc,speed,vx,vy,health, damage
	InitComponents(0, 0, 32, 32, 1, 3, 0, 0, 3, 1);
}

Player::~Player() { std::cout << "destroyed player\n"; }

