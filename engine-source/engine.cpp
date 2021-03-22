#include "engine.h"
#include "input.h"

namespace engine {

	int FPS;
	bool isChangeRoom = false;
	std::string room_path;

	void StartGame(char* title, int fps, int screen_w, int screen_h, int scale, bool fullscreen){
		Game* game;
		FPS = fps;
		const int frameDelay = 1000/fps;

		Uint32 frameStart;
		int frameTime;
		
		std::cout << "Ready to start the game\n";
		game = new Game();
		std::cout << "Game object created\n";
		game->init(title, 0, 0, screen_w, screen_h, scale, fullscreen);
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

	void EndGame(){
		Game::self->stop();
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

	int GetMouseX(){ return (InputMouse::Instance()->x / Renderer::self->scale + Renderer::self->xView); }
	int GetMouseY(){ return (InputMouse::Instance()->y / Renderer::self->scale + Renderer::self->yView); }

	List<Object*>::node* CreateObject(std::string _name, int _x, int _y){
		if(!Game::self->current_room)
			return NULL;
		Object* temp = object::CreateObject(_name, _x, _y);
		return Game::self->current_room->obj_manager->AddObject(temp);
	}

	void DestroyObject(List<Object*>::node* _id){
		std::cout << _id ;
		Game::self->current_room->obj_manager->DestroyObject(_id);
	}

	bool GetCollToPoint(Collider *_coll, int _x, int _y){
		return Collision::ColliderToPoint(_coll, _x, _y);
	}

	bool GetCollAABB(Collider *_colA, Collider *_colB){
		return Collision::AABB(_colA, _colB);
	}
	
	int GetViewX(){
		return Renderer::self->xView;
	}
	
	int GetViewY(){
		return Renderer::self->yView;
	}

	void SetView(int _x, int _y){
		Renderer::self->xView = _x;
		Renderer::self->yView = _y;
	}

	void SetViewClean(int _x, int _y){
		if(!Game::self->current_room)
			return;
		if(_x < 0)
			_x = 0;
		if(_y < 0)
			_y = 0;
		if(_x + Renderer::self->wView > Game::self->current_room->width)
			_x = Game::self->current_room->width - Renderer::self->wView;
		if(_y + Renderer::self->wView > Game::self->current_room->height)
			_y = Game::self->current_room->height - Renderer::self->wView;
		SetView(_x, _y);
	}

	void SetViewCenter(int _x, int _y){
		if(!Game::self->current_room)
			return;
		int rw = Renderer::self->wView;
		int rh = Renderer::self->hView;
		int cw = Game::self->current_room->width;
		int ch = Game::self->current_room->height;
		if(_x < rw / 2 )
			_x = rw / 2;
		if(_y < rh / 2)
			_y = rh / 2;
		if(_x + rw / 2 > cw)
			_x = cw - rw / 2;
		if(_y + rh / 2 > ch)
			_y = ch - rh / 2;
		SetView(_x - rw / 2, _y - rh / 2);
	}

	void SetFullscreen(){
		SDL_SetWindowFullscreen(Renderer::self->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	}

	//Drawing
	void DrawRectangle(int _depth, int _x, int _y, int _w, int _h){
		using j = Renderer;
		j::self->AddRectToRender(_depth, _x, _y, _w, _h, 0, 0, 0);
	}

	//Math
	float GetAngle2Points(int _x1, int _y1, int _x2, int _y2){
		return std::atan2(_y1 - _y2, _x1 - _x2) * 180 / 3.14;
	}

	bool PointOutsideRoom(int _x, int _y){
		if(!Game::self->current_room)
			return false;
		return (_x < 0 || _y < 0 || _x > Game::self->current_room->width || _y > Game::self->current_room->height);
	}
}
