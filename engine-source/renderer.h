#ifndef RENDERER_H
#define RENDERER_H
#include "gamelibs.h"

class Renderer;
class RenderSprite;


class Renderer {
	public:
		Renderer();
		int CreateWindow(char* _title, int _xpos, int _ypos, int _width, int _height, bool _fullscreen);
		void RenderWindow();
		void CloseWindow();
		void AddSpriteToRender(int _depth,bool _isComp, SDL_Texture* _tex, SDL_Rect* _sRect, SDL_Rect* _dRect, double _ang, SDL_Point* _offset, SDL_RendererFlip _flip);
		//static void Render();
		static SDL_Renderer* renderer;
		static Renderer* self;
		int xView, yView;
	private :
		SDL_Window* window;
		struct snode{
			RenderSprite* sprite = nullptr;
			int depth;
			snode* next = nullptr;
		}* hnode,* tempnode,* prevnode;
};


class RenderSprite {
	public:
		RenderSprite(bool _isComp, SDL_Texture* _tex, SDL_Rect* _sRect, SDL_Rect _dRect, double _ang, SDL_Point* _offset, SDL_RendererFlip _flip);
		~RenderSprite(){
			delete &dRect;
		}
		void draw(){
			if(isComplex){
				SDL_RenderCopyEx(Renderer::renderer, texture, sRect, &dRect, angle, offset, flipFlag);
				return;
			}
			SDL_RenderCopy(Renderer::renderer, texture, sRect, &dRect);
		}
	private:
		bool isComplex;
		SDL_Texture* texture;
		SDL_Rect* sRect;
		SDL_Rect dRect;
		double angle;
		SDL_Point* offset;
		SDL_RendererFlip flipFlag;
};

#endif
