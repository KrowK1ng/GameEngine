#ifndef GAME_ENGINE_START_H
#define GAME_ENGINE_START_H

#include "gamelibs.h"
#include "game.h"
#include "objects/object_manager.h"

namespace engine{
	void StartGame(char* title, int fps, int screen_w, int screen_h, bool fullscreen);
	void ChangeRoom(std::string relative_path);
	void EngineStep();

	int GetFPS();

	//Input
	bool GetKey(SDL_Scancode scanCode);
	bool GetKeyPressed(SDL_Scancode scanCode);
	bool GetKeyReleased(SDL_Scancode scanCode);
	///Mouse
	bool GetMButtonPressed(int button);
	bool GetMButtonReleased(int button);
	int GetMouseX();
	int GetMouseY();
	
	int CreateObject(std::string _name, int _x, int _y);
	void DestroyObject(ObjectManager::onode* _id);

	//Collision
	bool GetCollAABB(Collider* _colA, Collider* _colB);
	bool GetCollToPoint(Collider* _coll, int _x, int _y);
};

#endif
