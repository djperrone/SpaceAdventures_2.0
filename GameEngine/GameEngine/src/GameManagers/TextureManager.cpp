#include "TextureManager.h"

TextureManager::TextureManager()
{

}

SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
	//std::cout << "loading " << filename << std::endl;
	////TextureManager m;
	///*if (m.m_TextureCache.find(filename) != m_TextureCache.end())
	//{

	//}*/

	//SDL_Surface* tempSurface = nullptr;
	//tempSurface = IMG_Load(filename);
	////if (!tempSurface)
	//	//std::cout << "failed to load image "<<texture<<"\n";
	//std::cout << "IMG ERROR: " << IMG_GetError() << std::endl;
	//


	SDL_Texture* tex = nullptr;
	//tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	////if (!tex)
	//	//std::cout << "failed to load texture" << texture << "\n";

	//SDL_FreeSurface(tempSurface);


	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	//SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

