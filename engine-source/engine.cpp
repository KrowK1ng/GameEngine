#include "engine.h"
#include "input.h"

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

	bool GetKey(SDL_Scancode scanCode){
		return Input::Instance()->KeyDown(scanCode);
	}

	bool GetKeyPressed(SDL_Scancode scanCode){
		return Input::Instance()->KeyPressed(scanCode);
	}

	bool GetKeyReleased(SDL_Scancode scanCode){
		return Input::Instance()->KeyReleased(scanCode);
	}

	bool GetMButtonPressed(int button){
		return InputMouse::GetPressed(static_cast<InputMouse::MButtons>(button));
	}

	bool GetMButtonReleased(int button){
		return InputMouse::GetReleased(static_cast<InputMouse::MButtons>(button));
	}

	int GetMouseX(){ return InputMouse::Instance()->x; }
	int GetMouseY(){ return InputMouse::Instance()->y; }

	int CreateObject(std::string _name, int _x, int _y){
		if(!Game::self->current_room)
			return 0;
		Object* temp = object::CreateObject(_name, _x, _y);
		Game::self->current_room->obj_manager->AddObject(temp);
		return 1;
	}

	void DestroyObject(ObjectManager::onode *_id){
		Game::self->current_room->obj_manager->DestroyObject(_id);
	}

	bool GetCollToPoint(Collider *_coll, int _x, int _y){
		return Collision::ColliderToPoint(_coll, _x, _y);
	}

	bool GetCollAABB(Collider *_colA, Collider *_colB){
		return Collision::AABB(_colA, _colB);
	}
}
