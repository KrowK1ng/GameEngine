#include "texturemanager.h"

SDL_Texture* TextureManager::LoadTexture(const char* _filename, SDL_Renderer* _ren){
	SDL_Surface* tempSurface = IMG_Load(_filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(_ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}
