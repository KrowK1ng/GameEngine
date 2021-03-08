#include "obj_floor.h"
#include "engine.h"

Floor::onode* Floor::hnode = nullptr;
Floor::onode* Floor::lastnode = nullptr;

Floor::Floor(int _x,int _y)
	: Object(_x, _y)
{
	AddObejct();
	Start();
}

Floor::~Floor(){
	DestroyObject();
}

Floor* Floor::Initialize(int _x, int _y){
	return new Floor(_x, _y);
}

void Floor::Start(){
	std::cout << "Start\n";
	Tile = new Sprite("assets/chess.png",16,16,0,0,0,0,6);
	collider = new Collider(&x , &y, 96, 96);
}

void Floor::Step(){
	if(engine::GetMButtonPressed(0)){
		if(engine::GetCollToPoint(collider, engine::GetMouseX(), engine::GetMouseY())){
			std::cout << "Pressed on " << x << " " << y << "\n";
			engine::DestroyObject(id);
		}
	}
	//std::cout << "Step\n";
}

void Floor::Draw(){
	//std::cout << "Draw\n";
	Tile->Render(x,y);
}

void Floor::Destroy(){
	delete this;
}

void Floor::AddObejct(){
	std::cout << "Created\n";
	if(!hnode){
		hnode = new onode;
		lastnode = hnode;
		hnode->object = this;
	}else{
		lastnode->next = new onode;
		lastnode->next->prev = lastnode;
		lastnode = lastnode->next;
		lastnode->object = this;
	}
	snode = lastnode;
}

void Floor::DestroyObject(){
	if(!snode)
		return;
	if(!snode->prev){
		if(!snode->next){
			hnode = nullptr;
			lastnode = nullptr;
		}else{
			hnode = snode->next;
			hnode->prev = nullptr;
		}
	}else{
		if(!snode->next){
			snode->prev->next = nullptr;
			lastnode = snode->prev;
		}else{
			snode->next->prev = snode->prev;
			snode->prev->next = snode->next;
		}
	}
	delete snode;
}

Object::onode* Floor::GetHeadNode(){
	return hnode;
}
