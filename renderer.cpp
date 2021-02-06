#include "renderer.h"

using namespace std;

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

	return 1;
}

void Renderer::RenderWindow(){
	SDL_RenderPresent(renderer);

	return;
}

void Renderer::CloseWindow(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
