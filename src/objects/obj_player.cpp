#include "obj_player.h"
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
}

void Player::Step(){
	xspeed = 0;
	yspeed = 0;
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
	x += xspeed;
	if(engine::GetMButtonPressed(0))
		engine::CreateObject("Floor", engine::GetMouseX(), engine::GetMouseY());
	if(engine::GetKeyPressed(SDL_SCANCODE_W)){
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
	}
}

void Player::Draw(){
	SDL_RendererFlip _flip = SDL_FLIP_NONE;
	if(flipDirection)
		_flip = SDL_FLIP_HORIZONTAL;
	if(xspeed)
		PlayerWalk->RenderExt(x,y,0,_flip);
	else
		PlayerNormal->RenderExt(x,y,0,_flip);
}
