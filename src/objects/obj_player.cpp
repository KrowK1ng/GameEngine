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
	PlayerNormal = new Sprite("assets/spr_player.png",32,32,0,0,16,16,2);
	PlayerWalk = new AnimatedSprite("assets/spr_player.png",32,32,0,32,16,16,2,8,6);
}

void Player::Step(){
	if(engine::GetKey(SDL_SCANCODE_D)){
		x += 4;
	}
	if(engine::GetKey(SDL_SCANCODE_A)){
		x -= 4;
	}
}

void Player::Draw(){
	//PlayerNormal->Render(x,y);
	PlayerWalk->Render(x,y);
}
