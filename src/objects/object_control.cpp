#include "engine.h"
#include "object_control.h"
//#include "objects/object_manager.h"

ObjectControl::ObjectControl(int _x, int _y)
	: Object(_x,_y)
{}

void ObjectControl::Start(){
	WhiteSquare = new Sprite("assets/chess.png",16,16,0,16,0,0);
	BlackSquare = new Sprite("assets/chess.png",16,16,0,0,0,0);
	l = 0;
}

void ObjectControl::Step(){
	l++;
	l = l % 300;
	if(!l){
		std::cout << "Ten seconds have passed\n";
		engine::ChangeRoom("room1");
	}
}

void ObjectControl::Draw(){
	for(int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			if(( i + j ) % 2)
				WhiteSquare->Render(i * 16, j * 16);
			else
				BlackSquare->Render(i * 16, j * 16);
		}
	}
}
