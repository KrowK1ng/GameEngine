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
		static bool ColliderToPoint(Collider* coll, int _x, int _y);
		static bool LineToLine(int _Ax1, int _Ay1, int _Ax2, int _Ay2, int _Bx1, int _By1, int _Bx2, int _y2);
};
#endif
