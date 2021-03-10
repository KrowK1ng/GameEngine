#ifndef OBJ_PLAYER_H
#define OBJ_PLAYER_H
//#include "../../engine-source/object.h"
#include "object.h"

class Player : public Object{
	private:
		static Player* sInstance;
		Player(int _x, int _y);
		~Player();
		float jSpeed = -15;
		float g = 60;
	public:
		static Player* Initialize(int _x, int _y);
		void Start();
		void Step();
		void Draw();

		Sprite* PlayerNormal;
		AnimatedSprite* PlayerWalk;
		Collider* downCollider;
		float xspeed,yspeed, flipDirection;
		float fx, fy;
};

#endif
