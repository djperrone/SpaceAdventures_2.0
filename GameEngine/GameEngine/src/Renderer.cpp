#include "Renderer.h"
#include <iostream>

Renderer::Renderer(SDL_Renderer* renderer)
	: m_Renderer(renderer) {
	"constructed renderer!\n";
}
	



void Renderer::Render(GameObject* obj)
{
	//SDL_RenderClear(m_Renderer); 	

	//SDL_RenderCopy(m_Renderer,LoadTexture(obj->GetImageName().c_str()), NULL, &(obj->GetDestRect()));

	//int tempw = (int)(obj->GetDestRect().w / 2);// * obj->GetScale() / 2);
	//int temph = (int)(obj->GetDestRect().h / 2);// *obj->GetScale() / 2);
	//SDL_Point point = { tempw, temph };
	SDL_RenderCopyEx(m_Renderer, LoadTexture(obj->GetImageName().c_str()), NULL, &(obj->GetDestRect()), obj->GetAngle(), NULL, SDL_FLIP_NONE);

}

SDL_Texture* Renderer::LoadTexture(const char* filename)
{
	
	
	if (m_TextureCache.find(filename) != m_TextureCache.end())
	{
		//std::cout << "in IMG ERROR: " << IMG_GetError() << std::endl;

		return m_TextureCache[filename];
	}

	std::cout << "loading " << filename << std::endl;

	SDL_Surface* tempSurface = nullptr;
	tempSurface = IMG_Load(filename);
	//if (!tempSurface)
		//std::cout << "failed to load image "<<texture<<"\n";
	//std::cout << "IMG ERROR: " << IMG_GetError() << std::endl;

	SDL_Texture* tex = nullptr;
	tex = SDL_CreateTextureFromSurface(m_Renderer, tempSurface);
	//if (!tex)
		//std::cout << "failed to load texture" << texture << "\n";

	SDL_FreeSurface(tempSurface);

	m_TextureCache[filename] = tex;
	return tex;
}

//void Renderer::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
//{
//	SDL_RenderCopy(m_Renderer, tex, &src, &dest);
//}