#pragma once
#include "MyObjects/Ship.h"
#include "Dimensions.h"
#include <string>
#include "ObjectTemplates/MouseCursor.h"

#define PI 3.14159265358979323846



class Player : public Ship
{

public:	
	Player(MouseCursor* mouseCursor);
	Player(std::string imageFile, int x, int y);

	virtual void Update() override;

	~Player();

	//void Update();		
	//float GetAngle(int x1, int y1, int x2, int y2);
	//void Rotate(SDL_Texture* texture, int x, int y, float angle);

	//void InitComponents() override;
	//void InitComponents(int x, int y) override;



private:
	Dimensions dimensions;
	MouseCursor* m_MouseCursor;

	/*TransformComponent* m_TransformComponent;
	TextureComponent* m_TextureComponent;
	std::unique_ptr<ComponentManager> m_ComponentManager;*/
	//SDL_Texture* objTexture;
	//SDL_Rect srcRect, destRect;
};
