#ifndef GAME_H
#define GAME_H

#include "gamelibs.h"
#include "object.h"
#include "renderer.h"

class Game {
	public:
		Game();
		~Game();

		void init(char* _title, int _xpos, int _ypos, int _width, int _height, bool _fullscreen);
		void input();
		void update();
		void render();
		void clean();
		
		bool running(){return isRunning;}
		static Renderer* renderer;
		ObjectManager* obj_manager;
	private : 
		bool isRunning;
};
#endif
