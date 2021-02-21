#include "engine.h"

Game* Engine::game = nullptr;

void Engine::StartGame(char* title, int fps, int screen_w, int screen_h, bool fullscreen){
	const int FPS = fps;
	const int frameDelay = 1000/fps;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init(title, 0, 0, screen_w, screen_h, fullscreen);
	
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
}
