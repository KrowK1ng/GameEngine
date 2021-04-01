#include "renderer.h"

SDL_Renderer* Renderer::renderer;
Renderer* Renderer::self;

Renderer::Renderer(){}

int Renderer::CreateWindow(char* _title, int _xpos, int _ypos, int _width, int _height, bool _fullscreen){
	if ( SDL_Init(SDL_INIT_VIDEO) ){
		printf("error initializing SDL: %s\n", SDL_GetError());
		return 0;
	}

	TTF_Init();			//TEMP
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 2048) < 0){		//TEMP
		printf("Error opening audio (remember to add error)\n");
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
	xView = yView = 0;
	scale = 2;
	hView = _height;
	wView = _width;
	//hView = _height / scale;
	//wView = _width / scale;
	return 1;
}

void Renderer::RenderStart(){
	RenderList.AddFirst(nullptr);
	SDL_RenderClear(Renderer::renderer);
}

void Renderer::RenderWindow(){
	List<RenderObject*>::node* tempnode = RenderList.hnode->next;
	while(tempnode){
		tempnode->data->draw();				//Draw Object
		delete tempnode->data;
		tempnode = tempnode->next;
	}

	RenderList.Clear();

	SDL_RenderPresent(renderer);

	return;
}

void Renderer::AddRenderObject(RenderObject* _obj){
	List<RenderObject*>::node* tempnode = RenderList.hnode;
	while(tempnode->next){
		if(tempnode->next->data->depth > _obj->depth){
			RenderList.AddAtNode( _obj, tempnode);
			return;
		}
		tempnode = tempnode->next;
	}
	RenderList.AddLast(_obj);
}

void Renderer::CloseWindow(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}

void Renderer::AddSpriteToRender(int _depth,bool _isComp, SDL_Texture* _tex, SDL_Rect* _sRect, SDL_Rect* _dRect, double _ang, SDL_Point* _offset, SDL_RendererFlip _flip){
	RenderSprite *tempSprite = new RenderSprite( _isComp, _tex, _sRect,  *_dRect, _ang, _offset, _flip);
	tempSprite->depth = _depth;
	AddRenderObject(tempSprite);
}

void Renderer::AddRectToRender(int _depth, int _x, int _y, int _w, int _h, int _r, int _g, int _b){
	RenderRectangle* tempSprite = new RenderRectangle(_x, _y, _w, _h, _r, _g, _b);
	tempSprite->depth = _depth;
	AddRenderObject(tempSprite);
}

void Renderer::AddTextToRender(int _depth, SDL_Texture* _texture, SDL_Rect _tRect){
	RenderText* tempText = new RenderText(_texture, _tRect);
	tempText->depth = _depth;
	AddRenderObject(tempText);
}
////Render Sprite

RenderSprite::RenderSprite(bool _isComp, SDL_Texture* _tex, SDL_Rect* _sRect, SDL_Rect _dRect, double _ang, SDL_Point* _offset, SDL_RendererFlip _flip)
	: RenderObject(), isComplex(_isComp), texture(_tex), sRect(_sRect), dRect(_dRect), angle(_ang), flipFlag(_flip)
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
	: RenderObject(), r(_r), g(_g), b(_b)
{
	rect = new SDL_Rect();
	rect->x = (_x - Renderer::self->xView) * Renderer::self->scale;
	rect->y = (_y - Renderer::self->yView) * Renderer::self->scale;
	rect->w = _w * Renderer::self->scale;
	rect->h = _h * Renderer::self->scale;
}

RenderText::RenderText(SDL_Texture* _texture, SDL_Rect _tRect)
	: RenderObject(), texture(_texture)
{
	tRect.x = (_tRect.x - Renderer::self->xView) * Renderer::self->scale;
	tRect.y = (_tRect.y - Renderer::self->yView) * Renderer::self->scale;
	tRect.w = _tRect.w;
	tRect.h = _tRect.h;
}
