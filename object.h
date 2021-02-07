#ifndef OBJECT_H
#define OBJECT_H
#include "sprite.h"
#include "gamelibs.h"

class Object{
	
	public:
		Object(int _x, int _y);
		void AddSprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff);
		virtual void Start();
		virtual void Step();
		virtual void Draw();

		int x, y;
		Sprite* sprite = nullptr; 

};

#endif
