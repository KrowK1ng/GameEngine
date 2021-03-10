#include "obj_player.h"
#include "collision.h"
#include "engine.h"
#include "object.h"

Player::Player(int _x, int _y)
	: Object(_x, _y)
{
	Start();
}

Player::~Player(){}

Player* Player::sInstance = NULL;

Player* Player::Initialize(int _x, int _y){
	if(sInstance == NULL)
		sInstance = new Player(_x, _y);
	return sInstance;
}

void Player::Start(){
	PlayerNormal = new Sprite("assets/spr_player.png",32,32,0,0,16,16,3);
	PlayerWalk = new AnimatedSprite("assets/spr_player.png",32,32,0,32,16,16,3,8,6);
	flipDirection = 0;
	PlayerNormal->depth = -1;
	PlayerWalk->depth = 1;
	fx = x;
	fy = y;
	yspeed = 0;
	downCollider = new Collider(&x, &y, -32, 48, 64, 6, "player");
}

void Player::Step(){
	xspeed = 0;
	if(engine::GetKey(SDL_SCANCODE_D)){
		xspeed += 4;
	}
	if(engine::GetKey(SDL_SCANCODE_A)){
		xspeed -= 4;
	}
	if(xspeed > 0)
		flipDirection = 0;
	if(xspeed < 0)
		flipDirection = 1;
	fx += xspeed;
	x = (int)fx;
	
	//gravity
	bool isGrounded = false;
	Object::onode* _l = Floor::GetHeadNode();
	int Gy;
	while(_l && !isGrounded){
		isGrounded = engine::GetCollAABB(downCollider, _l->object->collider);
		if(isGrounded)
			Gy = *_l->object->collider->y + _l->object->collider->offset_y;
		_l = _l->next;
	}
	if(!isGrounded){
		yspeed +=  g / engine::GetFPS();
	}else if (yspeed >= 0){
		//std::cout << "Grounded\n";
		//fy = 128;
		yspeed = 0;
		fy = Gy - 48;
		if(engine::GetKeyPressed(SDL_SCANCODE_SPACE)){
			yspeed = jSpeed;
			//std::cout << "Space \n" << SDL_SCANCODE_A << " " << SDL_SCANCODE_Z << "\n";
		}
	}else{
		yspeed +=  g / engine::GetFPS();
	}
	//temp
	//
	/*yspeed = 0;
	if(engine::GetKey(SDL_SCANCODE_S)){
		yspeed += 4;
	}
	if(engine::GetKey(SDL_SCANCODE_W)){
		yspeed -= 4;
	}*/
	fy += yspeed;
	y = (int)fy;
	//

	//if(engine::GetMButtonPressed(0))
		//engine::CreateObject("Floor", engine::GetMouseX(), engine::GetMouseY());
	/*if(engine::GetKeyPressed(SDL_SCANCODE_W)){
		Object::onode* _l = Floor::GetHeadNode();
		while(_l){
			std::cout << "Floor Object on " << _l->object->x << " " << _l->object->y << "\n";
			_l = _l->next;
		}
	}
	if(engine::GetKeyPressed(SDL_SCANCODE_O)){
		Object::onode* _l = Object::GetHeadNode();
		while(_l){
			std::cout << "Object on " << _l->object->x << " " << _l->object->y << "\n";
			_l = _l->next;
		}
	}*/
}

void Player::Draw(){
	SDL_RendererFlip _flip = SDL_FLIP_NONE;
	if(flipDirection)
		_flip = SDL_FLIP_HORIZONTAL;
	if(xspeed)
		PlayerWalk->RenderExt(x - 48 ,y - 48,0,_flip);
	else
		PlayerNormal->RenderExt(x - 48,y - 48,0,_flip);
}
