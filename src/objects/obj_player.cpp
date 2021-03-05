#include "obj_player.h"
#include "engine.h"

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
