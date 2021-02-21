#ifndef SPRITE_H
#define SPRITE_H
#include "gamelibs.h"
#include "renderer.h"
#include "texturemanager.h"

class Sprite{
	public:
		Sprite(){}
		Sprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff);
		void Render(int _x, int _y);
		void Render(int _x, int _y, int _depth);

		SDL_Texture* texture;
		SDL_Rect* sRect;
		SDL_Rect* dRect;
		SDL_Point* offset;
		int scale;
		int depth;
};

#endif
