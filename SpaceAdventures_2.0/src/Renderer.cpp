#include "sapch.h"
#include "Renderer.h"
#include "ObjectTemplates/GameObject.h"

Renderer::Renderer(SDL_Renderer* renderer)
	: m_Renderer(renderer) {
	"constructed renderer!\n";
}

void Renderer::Render(GameObject* obj)
{	
	SDL_RenderCopyEx(m_Renderer, LoadTexture(obj->GetImageName().c_str()), NULL, &(obj->GetDestRect()), obj->GetAngle(), NULL, SDL_FLIP_NONE);
}

SDL_Texture* Renderer::LoadTexture(const char* filename)
{	
	if (m_TextureCache.find(filename) != m_TextureCache.end())
	{
		return m_TextureCache[filename];
	}
	
	SDL_Surface* tempSurface = nullptr;
	tempSurface = IMG_Load(filename);
	if (!tempSurface)
		std::cout << "IMG ERROR: " << IMG_GetError() << std::endl;	

	SDL_Texture* tex = nullptr;
	tex = SDL_CreateTextureFromSurface(m_Renderer, tempSurface);
	if (!tex)
		std::cout << "IMG ERROR: " << IMG_GetError() << std::endl;

	SDL_FreeSurface(tempSurface);

	m_TextureCache[filename] = tex;
	return tex;
}
