#include "PLACE_HOLDER_FILE_NAME.h"

PLACE_HOLDER_CLASS::onode* PLACE_HOLDER_CLASS::hnode = nullptr;
PLACE_HOLDER_CLASS::onode* PLACE_HOLDER_CLASS::lastnode = nullptr;

PLACE_HOLDER_CLASS::PLACE_HOLDER_CLASS(int _x,int _y)
	: Object(_x, _y)
{
	AddObejct();
	Start();
}

PLACE_HOLDER_CLASS::~PLACE_HOLDER_CLASS(){
	DestroyObject();
}

PLACE_HOLDER_CLASS* PLACE_HOLDER_CLASS::Initialize(int _x, int _y){
	return new PLACE_HOLDER_CLASS(_x, _y);
}

void PLACE_HOLDER_CLASS::Start(){

}

void PLACE_HOLDER_CLASS::Step(){

}

void PLACE_HOLDER_CLASS::Draw(){

}

void PLACE_HOLDER_CLASS::Destroy(){
	delete this;
}

void PLACE_HOLDER_CLASS::AddObejct(){
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

void PLACE_HOLDER_CLASS::DestroyObject(){
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

Object::onode* PLACE_HOLDER_CLASS::GetHeadNode(){
	return hnode;
}
