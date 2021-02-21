#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "gamelibs.h"

class TextureManager {
	public:
		static SDL_Texture* LoadTexture(const char* _filename, SDL_Renderer* _ren);
};
#endif
