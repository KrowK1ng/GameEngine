#include "collision.h"

Collider::Collider(int* _x, int* _y, int _width, int _height)
	: x(_x), y(_y), offset_x(0), offset_y(0), width(_width), height(_height), tag("null")
{}

Collider::Collider(int* _x, int* _y, int _offx, int _offy,int _width, int _height, std::string _tag)
	: x(_x), y(_y), offset_x(_offx), offset_y(_offy), width(_width), height(_height), tag(_tag)
{}

Collider::~Collider(){}

bool Collision::AABB(Collider *colA, Collider *colB){
	return (
				*colA->x + colA->offset_x + colA->width > *colB->x + colB->offset_x &&
				*colA->x + colA->offset_x < *colB->x + colB->offset_x + colB->width &&
				*colA->y + colA->offset_y + colA->height > *colB->y + colB->offset_y &&
				*colA->y + colA->offset_y < *colB->y + colB->offset_y + colB->height
			);
}

bool Collision::ColliderToPoint(Collider *coll, int _x, int _y){
	return (
				*coll->x + coll->offset_x + coll->width > _x &&
				*coll->x + coll->offset_x < _x &&
				*coll->y + coll->offset_y + coll->height > _y &&
				*coll->y + coll->offset_y < _y 
			);
}

bool Collision::LineToLine(int _Ax1, int _Ay1, int _Ax2, int _Ay2, int _Bx1, int _By1, int _Bx2, int _y2){
	return (
				true
			);
}
