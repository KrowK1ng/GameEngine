#ifndef SPRITE_H
#define SPRITE_H
#include "gamelibs.h"
#include "renderer.h"
#include "texturemanager.h"

class Sprite{
	public:
		Sprite(){}
		Sprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff, int _scale);
		virtual void Render(int _x, int _y);
		virtual void Render(int _x, int _y, int _depth);
		virtual void RenderExt(int _x, int _y, int _angle, SDL_RendererFlip _flip);
		virtual void RenderExt(int _x, int _y, int _depth, int _angle, SDL_RendererFlip _flip);

		SDL_Texture* texture;
		SDL_Rect* sRect;
		SDL_Rect* dRect;
		SDL_Point* offset;
		int scale;
		int depth;
};

class AnimatedSprite : public Sprite{
	private:
		int width, speed, frames, frame_counter;
	public:
		AnimatedSprite(){}
		AnimatedSprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff, int _scale, int _speed, int _frames);
		void Render(int _x, int _y) override;
		void Render(int _x, int _y, int _depth) override;
		void RenderExt(int _x, int _y, int _angle, SDL_RendererFlip _flip);
		void RenderExt(int _x, int _y, int _depth, int _angle, SDL_RendererFlip _flip);
		void ChangeImageSpeed(int _speed);
		void ChangeImageFrame(int _frame);
		bool isEnd();
		
		SDL_Texture* texture;
		SDL_Rect* sRect;
		SDL_Rect* dRect;
		SDL_Point* offset;
		int scale;
		int depth;
};

#endif
