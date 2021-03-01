#include "game.h"

Game::Game(){}
Game::~Game(){}
Renderer* Game::renderer;
Game* Game::self;

void Game::init(char* _title, int _xpos, int _ypos, int _width, int _height, bool _fullscreen){
	renderer = new Renderer();
	if(renderer->CreateWindow(_title, _xpos, _ypos, _width, _height, _fullscreen)){
		isRunning = true;
		std::cout << "Window Created succesefuly.\n" ;
	}
	InputManager = Input::Instance();
	current_room = nullptr;
	//Temp
	/*obj_manager = new ObjectManager();
	Object* tempobj = new Object(10,10);
	tempobj->depth = 3;
	tempobj->AddSprite("assets/spritesheet.png",  16, 16, 32, 0, 0, 0);
	obj_manager->AddObject(tempobj);
	tempobj = new Object(10,15);
	tempobj->depth = 5;
	tempobj->AddSprite("assets/spritesheet.png",  16, 16, 0, 0, 0, 0);
	obj_manager->AddObject(tempobj);*/
	current_room = new Room("assets/rooms/room0");
	//Singleton
	self = this;
}

void Game::input(){

	InputManager->Update();

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
	if (current_room)
		current_room->update();
}

void Game::render(){
	// Clear Render
	SDL_RenderClear(Renderer::renderer);

	// Prepare render
	if (current_room)
		current_room->render();
	//obj_manager->Draw();
	// Render
	renderer->RenderWindow();
	return;
}

void Game::clean(){
	renderer->CloseWindow();
	delete InputManager;
	delete renderer;
	isRunning = false;
}
