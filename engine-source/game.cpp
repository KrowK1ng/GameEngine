#include "game.h"

Game::Game(){}
Game::~Game(){}
Renderer* Game::renderer;
Game* Game::self;

void Game::init(char* _title, int _xpos, int _ypos, int _width, int _height, int _scale, bool _fullscreen){
	renderer = new Renderer();
	if(renderer->CreateWindow(_title, _xpos, _ypos, _width, _height, _fullscreen)){
		isRunning = true;
		std::cout << "Window Created succesefuly.\n" ;
	}
	renderer->scale = _scale;
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
	//Singleton
	self = this;

	current_room = new Room("assets/rooms/room0");

	SDL_RenderSetLogicalSize(renderer->renderer, _width * _scale, _height * _scale );
	//SDL_RenderSetScale(renderer->renderer, 2, 2);
	SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" );
}

void Game::input(){

	InputManager->Update();

	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_MOUSEMOTION:
				InputMouse::Instance()->x = event.motion.x;
				InputMouse::Instance()->y = event.motion.y;
				break;
			case SDL_MOUSEBUTTONDOWN:
				InputMouse::Instance()->MouseButtonState[event.button.button - 1] = InputMouse::pressed;
				break;
			case SDL_MOUSEBUTTONUP:
				InputMouse::Instance()->MouseButtonState[event.button.button - 1] = InputMouse::released;
				break;

			default:
				break;
		}
	}
}

void Game::update(){
	if (current_room)
		current_room->update();
}

void Game::render(){
	// Clear Render
	renderer->RenderStart();

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
