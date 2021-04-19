#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "gamelibs.h"

class TextureManager {
	public:
		static SDL_Texture* LoadTexture(const char* _filename, SDL_Renderer* _ren);
		static SDL_Texture* LoadTexture(const char* _filename, SDL_Renderer* _ren, Uint8 _alpha);
		static SDL_Texture* LoadTextureText(TTF_Font* _font, std::string _text, SDL_Color _color, SDL_Renderer* _ren);
		static SDL_Texture* LoadTextureTextTran(TTF_Font* _font, int _width, std::string _text, SDL_Color _color, SDL_Renderer* _ren);
};
#endif
