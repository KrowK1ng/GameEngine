#include "renderer.h"

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
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	self = this;
	hnode = new snode;
	hnode->depth = 0;
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
	RenderSprite *tempSprite = new RenderSprite( _isComp, _tex, _sRect,  _dRect, _ang, _offset, _flip);
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
