#include "renderer.h"
#include <SDL2/SDL_rect.h>

using namespace std;

SDL_Renderer* Renderer::renderer;
Renderer* Renderer::self;

Renderer::Renderer(){}

int Renderer::CreateWindow(char* _title, int _xpos, int _ypos, int _width, int _height, bool _fullscreen){
	if ( SDL_Init(SDL_INIT_VIDEO) ){
		printf("error initializing SDL: %s\n", SDL_GetError());
		return 0;
	}
	
	int flags = 0;
	if(_fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	window = SDL_CreateWindow(_title, 
			_xpos,
			_ypos,
			_width, _height, flags);
	
	if (!window){
		printf("error creating window: %s\n", SDL_GetError());
		SDL_Quit();
		return 0;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer){
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
	}
	
	SDL_SetRenderDrawColor(renderer, 20, 25, 25, 255);

	self = this;
	hnode = new snode;
	hnode->depth = 0;
	xView = yView = 0;
	scale = 2;
	hView = _height;
	wView = _width;
	//hView = _height / scale;
	//wView = _width / scale;
	return 1;
}

void Renderer::RenderWindow(){
	tempnode = hnode->next;
	while(tempnode){
		tempnode->sprite->draw();				//Draw Object
		prevnode = tempnode;
		tempnode = tempnode->next;
		delete prevnode;						//Clear List
	}
	hnode->next = nullptr;

	SDL_RenderPresent(renderer);

	return;
}

void Renderer::CloseWindow(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Renderer::AddSpriteToRender(int _depth,bool _isComp, SDL_Texture* _tex, SDL_Rect* _sRect, SDL_Rect* _dRect, double _ang, SDL_Point* _offset, SDL_RendererFlip _flip){
	RenderSprite *tempSprite = new RenderSprite( _isComp, _tex, _sRect,  *_dRect, _ang, _offset, _flip);
	if(hnode->next){							//Checks if a sprite was already added
		tempnode = hnode->next;
		prevnode = hnode;
		while(tempnode){
			if(tempnode->depth > _depth){		//If the sprite must be showed firts
				tempnode = new snode;
				tempnode->sprite = tempSprite;
				tempnode->depth = _depth;
				tempnode->next = prevnode->next;
				prevnode->next = tempnode;
				return;
			}
			prevnode = tempnode;
			tempnode = tempnode->next;
		}
		tempnode = new snode;					// If the sprite is at the end of the list
		tempnode->sprite = tempSprite;
		tempnode->depth = _depth;
		prevnode->next = tempnode;
	}else{										//Adds first sprite
		tempnode = new snode;
		hnode->next = tempnode;
		tempnode->depth = _depth;
		tempnode->sprite = tempSprite;
	}
}

void Renderer::AddRectToRender(int _depth, int _x, int _y, int _w, int _h, int _r, int _g, int _b){
	RenderRectangle* tempSprite = new RenderRectangle(_x, _y, _w, _h, _r, _g, _b);
	if(hnode->next){							//Checks if a sprite was already added
		tempnode = hnode->next;
		prevnode = hnode;
		while(tempnode){
			if(tempnode->depth > _depth){		//If the sprite must be showed firts
				tempnode = new snode;
				tempnode->sprite = tempSprite;
				tempnode->depth = _depth;
				tempnode->next = prevnode->next;
				prevnode->next = tempnode;
				return;
			}
			prevnode = tempnode;
			tempnode = tempnode->next;
		}
		tempnode = new snode;					// If the sprite is at the end of the list
		tempnode->sprite = tempSprite;
		tempnode->depth = _depth;
		prevnode->next = tempnode;
	}else{										//Adds first sprite
		tempnode = new snode;
		hnode->next = tempnode;
		tempnode->depth = _depth;
		tempnode->sprite = tempSprite;
	}
}
////Render Sprite

RenderSprite::RenderSprite(bool _isComp, SDL_Texture* _tex, SDL_Rect* _sRect, SDL_Rect _dRect, double _ang, SDL_Point* _offset, SDL_RendererFlip _flip)
	: isComplex(_isComp), texture(_tex), sRect(_sRect), dRect(_dRect), angle(_ang), flipFlag(_flip), RenderObject()
{
	dRect.x = (dRect.x - Renderer::self->xView) * Renderer::self->scale;
	dRect.y = (dRect.y - Renderer::self->yView) * Renderer::self->scale;
	dRect.w *= Renderer::self->scale;
	dRect.h *= Renderer::self->scale;
	if(_offset){
		offset = new SDL_Point();
		offset->x = _offset->x * Renderer::self->scale;
		offset->y = _offset->y * Renderer::self->scale;
	}else {
		offset = nullptr;
	}
	//offset.x *= Renderer::self->scale;
	//offset.y *= Renderer::self->scale;
};

RenderRectangle::RenderRectangle(int _x, int _y, int _w, int _h, int _r, int _g, int _b)
	: r(_r), g(_g), b(_b), RenderObject()
{
	rect = new SDL_Rect();
	rect->x = (_x - Renderer::self->xView) * Renderer::self->scale;
	rect->y = (_y - Renderer::self->yView) * Renderer::self->scale;
	rect->w = _w * Renderer::self->scale;
	rect->h = _h * Renderer::self->scale;
}
