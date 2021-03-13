#include "object.h"
#include <iostream>

Object::onode* Object::lastnode = nullptr;
Object::onode* Object::hnode = nullptr;

Object::Object(int _x, int _y)
	: x(_x), y(_y), depth(0)
{
	//printf("Object created on %d %d\n", _x, _y);
	AddObejct();
	std::cout << "OBJ Created\n";
}

Object::~Object(){
	DestroyObject();
	std::cout << "OBJ Destroyed\n";
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
	std::cout << "OBJ drawed\n";
}

void Object::Destroy(){
	delete this;
}

void Object::AddObejct(){
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

void Object::DestroyObject(){
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

Object::onode* Object::GetHeadNode(){
	return hnode;
}

ObjectManager::ObjectManager(){
	hnode = nullptr;
	lastnode = nullptr;
}

ObjectManager::~ObjectManager(){
	tempnode = hnode;
	while(tempnode){
		lastnode = tempnode;
		tempnode = tempnode->next;
		lastnode->object->Destroy();
		delete lastnode;
	}
}

ObjectManager::onode* ObjectManager::AddObject(Object* _point){
	if (!hnode){
		hnode = new onode;
		hnode->object = _point;
		lastnode = hnode;
	}else{
		lastnode->next = new onode;
		lastnode->next->prev = lastnode;
		lastnode->next->object = _point;
		lastnode = lastnode->next;
	}
	//_point->Start();
	_point->id = lastnode;
	return lastnode;
}

void ObjectManager::DestroyObject(onode *_id){
	if(!_id->prev){
		if(!_id->next){
			hnode = nullptr;
			lastnode = nullptr;
		}else{
			hnode = _id->next;
			_id->next->prev = nullptr;
		}
	}else{
		if(!_id->next){
			_id->prev->next = nullptr;
			lastnode = _id->prev;
		}else{
			_id->next->prev = _id->prev;
			_id->prev->next = _id->next;
		}
	}
	_id->object->Destroy();
	delete _id;
}

void ObjectManager::Step(){
	tempnode = hnode;
	while(tempnode){
		tempnode->object->Step();
		tempnode = tempnode->next;
	}
}

void ObjectManager::Draw(){
	tempnode = hnode;
	while(tempnode){
		tempnode->object->Draw();
		tempnode = tempnode->next;
	}
}
