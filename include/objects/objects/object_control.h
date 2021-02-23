#ifndef OBJECT_CONTROL_H
#define OBJECT_CONTROL_H
//#include "../../engine-source/object.h"
#include "object.h"

class ObjectControl : public Object{
	
	public:
		ObjectControl(int _x, int _y);
		~ObjectControl();
		void Start();
		void Step();
		void Draw();

		int table[8][8];
		int l;
		Sprite* WhiteSquare;
		Sprite* BlackSquare;
};

#endif
