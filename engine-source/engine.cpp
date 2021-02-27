#include "engine.h"

namespace engine {

	int FPS;
	bool isChangeRoom = false;
	std::string room_path;

	void StartGame(char* title, int fps, int screen_w, int screen_h, bool fullscreen){
		Game* game;
		FPS = fps;
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
			EngineStep();

			frameTime = SDL_GetTicks() - frameStart;
			
			if(frameDelay > frameTime){
				SDL_Delay(frameDelay - frameTime);
			}
		}
		game->clean();
	}

	void ChangeRoom(std::string relative_path){
		//char* rpath = "assets/rooms/";
		//strcat(rpath,relative_path);
		isChangeRoom = true;
		room_path = "assets/rooms/";
		room_path += relative_path;
		//strcat(room_path,relative_path);
		//delete Game::self->current_room;
		//Game::self->current_room = new Room("assets/rooms/room0");
	}

	void EngineStep(){
		if(isChangeRoom){
			delete Game::self->current_room;
			Game::self->current_room = new Room(room_path);
			isChangeRoom = false;
		}
	}

	int GetFPS(){
		return FPS;
	}
}
