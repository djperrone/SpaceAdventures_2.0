#pragma once

#include <unordered_map>

#include "SDL.h"
#include "SDL_image.h"

#include "GameObject.h"

//class GameObject;

//class TextureManager;

class Renderer
{
private:
	SDL_Renderer* m_Renderer;

	std::unordered_map<std::string, SDL_Texture*> m_TextureCache;
	//TextureManager* m_TextureManager;

	SDL_Texture* LoadTexture(const char* filename);
	void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
public:
	//should be a list eventually
	Renderer(SDL_Renderer* renderer);
	void Render(GameObject* object);
	
};

