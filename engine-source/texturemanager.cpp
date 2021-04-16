#include "texturemanager.h"

SDL_Texture* TextureManager::LoadTexture(const char* _filename, SDL_Renderer* _ren){
	return LoadTexture(_filename, _ren, 255);
}

SDL_Texture* TextureManager::LoadTexture(const char* _filename, SDL_Renderer* _ren, Uint8 _alpha){
	SDL_Surface* tempSurface = IMG_Load(_filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(_ren, tempSurface);
	SDL_SetTextureAlphaMod(tex, _alpha);
	SDL_FreeSurface(tempSurface);

	return tex;
}

SDL_Texture* TextureManager::LoadTextureText(TTF_Font* _font, std::string _text, SDL_Color _color, SDL_Renderer *_ren){
	SDL_Surface* tempSurface = TTF_RenderText_Solid(_font, _text.c_str(), _color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(_ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}
