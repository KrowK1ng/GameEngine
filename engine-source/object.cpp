#include "object.h"
#include <cstdio>

Object::Object(int _x, int _y)
	: x(_x), y(_y), depth(0)
{
	printf("Object created on %d %d\n", _x, _y);
}

Object::~Object(){}

void Object::AddSprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff){
	sprite = new Sprite(_source, _w, _h, _x, _y, _xoff, _yoff);
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

void ObjectManager::AddObject(Object* _point){
	if (!hnode){
		hnode = new onode;
		hnode->object = _point;
		lastnode = hnode;
	}else{
		lastnode->next = new onode;
		lastnode->next->prev = lastnode;
		lastnode->next->object = _point;
	}
	_point->Start();
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
