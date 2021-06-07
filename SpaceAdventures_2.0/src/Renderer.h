#pragma once

#include "SDL.h"
#include "SDL_image.h"

class GameObject;

class Renderer
{
private:
	SDL_Renderer* m_Renderer;
	std::unordered_map<std::string, SDL_Texture*> m_TextureCache;	
	SDL_Texture* LoadTexture(const char* filename);
	
public:	
	Renderer(SDL_Renderer* renderer);
	void Render(GameObject* object);
	
};

