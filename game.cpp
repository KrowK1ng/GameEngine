#include "game.h"
#include "renderer.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

Game::Game(){}
Game::~Game(){}

void Game::init(char* _title, int _xpos, int _ypos, int _width, int _height, bool _fullscreen){
	renderer = new Renderer();
	if(renderer->CreateWindow(_title, _xpos, _ypos, _width, _height, _fullscreen)){
		isRunning = true;
	}
}

void Game::input(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}
}

void Game::update(){
}

void Game::render(){
	// Clear Render
	SDL_RenderClear(renderer->GetRenderer());

	// Prepare render
	
	// Render
	renderer->RenderWindow();
	return;
}

void Game::clean(){
	renderer->CloseWindow();
	isRunning = false;
}
