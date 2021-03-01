#include "sprite.h"

Sprite::Sprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff, int _scale) {
	sRect = new SDL_Rect();
	dRect = new SDL_Rect();
	offset = new SDL_Point();
	sRect->x = _x;
	sRect->y = _y;
	sRect->w = _w;
	sRect->h = _h;
	texture = TextureManager::LoadTexture(_source, Renderer::self->renderer);
	offset->x = _xoff;
	offset->y = _yoff;
	dRect->x = 0;
	dRect->y = 0;
	scale = _scale;
	dRect->w = _w * _scale;
	dRect->h = _h * _scale;
	depth = 0;
	scale = 1;
}

void Sprite::Render(int _x, int _y){
	Render(_x, _y, depth);
}

void Sprite::Render(int _x, int _y, int _depth){
	dRect->x = _x;
	dRect->y = _y;
	SDL_Rect *tempRect = new SDL_Rect(*dRect);
	Renderer::self->AddSpriteToRender(_depth, false, texture, sRect, tempRect , 0,  nullptr, SDL_FLIP_NONE);
}
