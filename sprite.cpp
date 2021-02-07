#include "sprite.h"

Sprite::Sprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff) {
	sRect->x = _x;
	sRect->y = _y;
	sRect->w = _w;
	sRect->h = _h;
	texture = TextureManager::LoadTexture(_source, Game::renderer->renderer);
	offset->x = _xoff;
	offset->y = _yoff;
	dRect->x = 0;
	dRect->y = 0;
	depth = 0;
	scale = 0;
}

void Sprite::Render(int _x, int _y){
	Render(_x, _y, depth);
}

void Sprite::Render(int _x, int _y, int _depth){
	dRect->x = _x;
	dRect->y = _y;
	Game::renderer->AddSpriteToRender(_depth, false, texture, sRect, dRect, 0,  nullptr, SDL_FLIP_NONE);
}
