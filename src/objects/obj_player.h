#ifndef OBJ_PLAYER_H
#define OBJ_PLAYER_H
//#include "../../engine-source/object.h"
#include "object.h"

class Player : public Object{
	private:
		static Player* sInstance;
		Player(int _x, int _y);
		~Player();
	public:
		static Player* Initialize(int _x, int _y);
		void Start();
		void Step();
		void Draw();

		Sprite* PlayerNormal;
		AnimatedSprite* PlayerWalk;
		int xspeed,yspeed, flipDirection;
};

#endif
