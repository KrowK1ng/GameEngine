#include "obj_floor.h"

Floor::Floor(int _x,int _y)
	: Object(_x, _y)
{
	Start();
}

Floor::~Floor(){
	std::cout << "Destroyed\n";
}

Floor* Floor::Initialize(int _x, int _y){
	return new Floor(_x, _y);
}

void Floor::Start(){
	std::cout << "Start\n";
	Tile = new Sprite("assets/chess.png",16,16,0,0,0,0,6);
}

void Floor::Step(){
	//std::cout << "Step\n";
}

void Floor::Draw(){
	//std::cout << "Draw\n";
	Tile->Render(x,y);
}
