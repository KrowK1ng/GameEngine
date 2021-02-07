#include "object.h"

Object::Object(int _x, int _y)
	: x(_x), y(_y)
{}

void Object::AddSprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff){
	sprite = new Sprite(_source, _w, _h, _x, _y, _xoff, _yoff);
}

void Object::Start(){}

void Object::Step(){}

void Object::Draw(){
	sprite->Render(x, y);
}
