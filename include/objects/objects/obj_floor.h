#ifndef OBJ_FLOOR_H
#define OBJ_FLOOR_H
#include "object.h"

class Floor : public Object{
	private:
		Floor(int _x, int _y);
		~Floor();
	public:
		static Floor* Initialize(int _x, int _y);
		void Start();
		void Draw();

		Sprite* Tile;
};

#endif
