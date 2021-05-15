#pragma once
//#include "game.h"
#include <unordered_map>
#include "SDL.h"


class TextureManager
{
private:
	mutable std::unordered_map<std::string, SDL_Texture*> m_TextureCache;
public:

	TextureManager();
	SDL_Texture* LoadTexture(const char* filename);
	void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

