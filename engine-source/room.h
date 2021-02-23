#ifndef ROOM_H
#define ROOM_H

#include "gamelibs.h"
#include "object.h"

class Room {
	public:
		Room(char* path);
		~Room();

		void update();
		void render();

		ObjectManager* obj_manager = nullptr;
		int width, height;
};

#endif
