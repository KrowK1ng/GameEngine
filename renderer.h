#ifndef RENDERER_H
#define RENDERER_H
#include "gamelibs.h"

class Renderer {
	public:
		Renderer();
		int CreateWindow(char* _title, int _xpos, int _ypos, int _width, int _height, bool _fullscreen);
		void RenderWindow();
		void CloseWindow();
		SDL_Renderer* GetRenderer(){ return renderer; }
		//static void Render();
	private :
		SDL_Window* window;
		SDL_Renderer* renderer;
};

#endif
