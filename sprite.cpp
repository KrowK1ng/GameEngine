#include "sprite.h"

Sprite::Sprite(SDL_Renderer* _ren, const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff) {
	sRect->x = _x;
	sRect->y = _y;
	sRect->w = _w;
	sRect->h = _h;
	TextureManager::LoadTexture(_source, _ren);
	offset->x = _xoff;
	offset->y = _yoff;
	dRect->x = 0;
	dRect->x = 0;
}

void Sprite::Render(SDL_Renderer* _ren, int _x, int _y){
	dRect->x = _x;
	dRect->y = _y;
	SDL_RenderCopy(_ren, texture, sRect, dRect);
}
