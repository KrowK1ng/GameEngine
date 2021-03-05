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

void Sprite::RenderExt(int _x, int _y, int _angle, SDL_RendererFlip _flip){
	RenderExt(_x, _y, depth, _angle, _flip);
}

void Sprite::RenderExt(int _x, int _y, int _depth, int _angle, SDL_RendererFlip _flip){
	dRect->x = _x;
	dRect->y = _y;
	SDL_Rect *tempRect = new SDL_Rect(*dRect);
	Renderer::self->AddSpriteToRender(_depth, true, texture, sRect, tempRect , _angle,  offset, _flip);
}

AnimatedSprite::AnimatedSprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff, int _scale, int _speed, int _frames) {
	sRect = new SDL_Rect();
	dRect = new SDL_Rect();
	offset = new SDL_Point();
	sRect->x = 0;
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
	width = _w;
	frames = _frames;
	speed = _speed;
	frame_counter = 0;
}

void AnimatedSprite::Render(int _x, int _y){
	Render(_x, _y, depth);
}

void AnimatedSprite::Render(int _x, int _y, int _depth){
	// Frames and stuff
	frame_counter++;
	frame_counter = frame_counter % (speed * frames);
	int _frame = frame_counter / speed;

	sRect->x = _frame * width;
	dRect->x = _x;
	dRect->y = _y;
	SDL_Rect *tempRect = new SDL_Rect(*dRect);
	Renderer::self->AddSpriteToRender(_depth, false, texture, sRect, tempRect , 0,  nullptr, SDL_FLIP_NONE);
}

void AnimatedSprite::ChangeImageSpeed(int _speed){
	frame_counter = (frame_counter / speed) * speed;
	speed = _speed;
}

void AnimatedSprite::ChangeImageFrame(int _frame){
	frame_counter = (_frame % frames) * speed;
}

void AnimatedSprite::RenderExt(int _x, int _y, int _angle, SDL_RendererFlip _flip){
	RenderExt(_x, _y, depth, _angle, _flip);
}

void AnimatedSprite::RenderExt(int _x, int _y, int _depth, int _angle, SDL_RendererFlip _flip){
	// Frames and stuff
	frame_counter++;
	frame_counter = frame_counter % (speed * frames);
	int _frame = frame_counter / speed;

	sRect->x = _frame * width;
	dRect->x = _x;
	dRect->y = _y;
	SDL_Rect *tempRect = new SDL_Rect(*dRect);
	Renderer::self->AddSpriteToRender(_depth, true, texture, sRect, tempRect , _angle,  offset, _flip);
}
