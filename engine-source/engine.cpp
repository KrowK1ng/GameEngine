#include "engine.h"

namespace engine {

	void StartGame(char* title, int fps, int screen_w, int screen_h, bool fullscreen){
		Game* game;
		const int FPS = fps;
		const int frameDelay = 1000/fps;

		Uint32 frameStart;
		int frameTime;
		
		std::cout << "Ready to start the game\n";
		game = new Game();
		std::cout << "Game object created\n";
		game->init(title, 0, 0, screen_w, screen_h, fullscreen);
		std::cout << "The window was created\n";
		
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

	void ChangeRoom(char *relative_path){
		char* rpath = "assets/rooms/";
		strcat(rpath,relative_path);
		delete Game::self->current_room;
		Game::self->current_room = new Room(rpath);
	}
}
