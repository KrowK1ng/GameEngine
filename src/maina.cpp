#include <SDL2/SDL_stdinc.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include "game.h"

using namespace std;

Game *game = nullptr;

int main(){
	
	const int fps = 30;
	const int frameDelay = 1000/fps;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Snake", 0, 0, 480, 480, false);
	
	while(game->running()){

		frameStart = SDL_GetTicks();

		game->input();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		
		if(frameDelay > frameTime){
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	//SDL_DestroyWindow(win);
	//SDL_Quit();
}
