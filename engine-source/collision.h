#ifndef GAME_ENGIGNE_COLLISION_H
#define GAME_ENGIGNE_COLLISION_H
#include "gamelibs.h"

class Collider{
	public:
		Collider(int* _x, int* _y, int _width, int _height);
		Collider(int* _x, int* _y, int _offx, int _offy,int _width, int _height, std::string _tag);
		~Collider();
		int *x, *y;
		int offset_x, offset_y;
		int width,height;
		std::string tag;
};

class Collision{
	private:
		Collision();
		~Collision();
	public:
		static bool AABB(Collider* colA, Collider* colB);
};
#endif
