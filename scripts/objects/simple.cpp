#include "PLACE_HOLDER_FILE_NAME.h"

List<Object*>::node* PLACE_HOLDER_CLASS::ObjectList;

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
	ObjectList.AddLast(this);
	snode = ObjectList.lastnode;
}

void PLACE_HOLDER_CLASS::DestroyObject(){
	if(!snode)
		return;
	ObjectList.RemoveData(snode);
}

List<Object*>::node* PLACE_HOLDER_CLASS::GetHeadNode(){
	return ObjectList.hnode;
}
