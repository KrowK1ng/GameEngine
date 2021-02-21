#include "room.h"

Room::Room(){
	obj_manager = new ObjectManager();
}

Room::~Room(){
	delete obj_manager;
}

void Room::update(){
	obj_manager->Step();
}

void Room::render(){
	obj_manager->Draw();
}
