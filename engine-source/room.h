#ifndef ROOM_H
#define ROOM_H

#include "gamelibs.h"
#include "object.h"

class Room {
	public:
		Room();
		~Room();

		virtual void start();
		virtual void update();
		virtual void render();

		ObjectManager* obj_manager;
		int width, height;
};

#endif
