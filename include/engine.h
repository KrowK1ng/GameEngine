#ifndef GAME_ENGINE_START_H
#define GAME_ENGINE_START_H

#include "gamelibs.h"
#include "game.h"

class Engine{
	public:
		static Game* game;

		static void StartGame(char* title, int fps, int screen_w, int screen_h, bool fullscreen);
};

#endif
