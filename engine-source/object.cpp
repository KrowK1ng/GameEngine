#include "object.h"
#include <iostream>

//using lis = List<Object*>;

List<Object*> Object::ObjectList;

Object::Object(int _x, int _y)
	: x(_x), y(_y), depth(0)
{
	AddObejct();
}

Object::~Object(){
	DestroyObject();
}

Object* Object::Initialize(int _x, int _y){
	return new Object(_x,_y);
}

void Object::AddSprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff, int _scale){
	sprite = new Sprite(_source, _w, _h, _x, _y, _xoff, _yoff, _scale);
	sprite->depth = depth;
}

void Object::Start(){}

void Object::Step(){}

void Object::Draw(){
	sprite->Render(x, y);
}

void Object::Destroy(){
	delete this;
}

void Object::AddObejct(){
	ObjectList.AddLast(this);
	snode = ObjectList.lastnode;
}

void Object::DestroyObject(){
	if(!snode)
		return;
	ObjectList.RemoveData(snode);
}

List<Object*>::node* Object::GetHeadNode(){
	return ObjectList.hnode;
}

ObjectManager::ObjectManager(){
}

ObjectManager::~ObjectManager(){
	delete &ObjectList;
	delete &DestroyList;
}

List<Object*>::node* ObjectManager::AddObject(Object* _point){
	ObjectList.AddLast(_point);
	//_point->Start();
	_point->id = ObjectList.lastnode;
	return ObjectList.lastnode;
}

void ObjectManager::DestroyObject(List<Object*>::node *_id){
	if(DestroyList.IsData(_id))
		return;
	DestroyList.AddLast(_id);
}

void ObjectManager::Step(){
	tempnode = ObjectList.hnode;
	while(tempnode){
		//std::cout << tempnode << " "  << tempnode->next << "\n";		//Temp
		//if(!tempnode)
		//	std::cout << "NoTemp\n";		//Temp
		//if(!tempnode->data)
		//	std::cout << "NoData\n";		//Temp
		tempnode->data->Step();
		//std::cout << tempnode << " "  << tempnode->next << "\n";		//Temp
		//if(!tempnode)
		//	std::cout << "NoTemp\n";		//Temp
		//if(!tempnode->data)
		//	std::cout << "NoData\n";		//Temp
		tempnode = tempnode->next;
		//std::cout << "END\n";		//Temp
	}
		//std::cout << "EndEND\n";		//Temp
}

void ObjectManager::Draw(){
	tempnode = ObjectList.hnode;
	while(tempnode){
		tempnode->data->Draw();
		tempnode = tempnode->next;
	}
}

void ObjectManager::Destroy(){
	List<List<Object*>::node*>::node* tempnode = DestroyList.hnode;
	while(tempnode){
		tempnode->data->data->Destroy();
		ObjectList.RemoveData(tempnode->data);
		tempnode = tempnode->next;
	}
	DestroyList.Clear();
}
