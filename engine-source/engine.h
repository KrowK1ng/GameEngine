#ifndef GAME_ENGINE_START_H
#define GAME_ENGINE_START_H

#include "gamelibs.h"
#include "game.h"

namespace engine{
	void StartGame(char* title, int fps, int screen_w, int screen_h, bool fullscreen);
	void ChangeRoom(std::string relative_path);
	void EngineStep();

	int GetFPS();
};

#endif
