#include "object_manager.h"

namespace object{
	Object* CreateObject(std::string name, int x, int y){
		if (name == "Floor") return Floor::Initialize(x,y);
		if (name == "ObjectControl") return ObjectControl::Initialize(x,y);
		if (name == "Boy") return Boy::Initialize(x,y);
		if (name == "Player") return Player::Initialize(x,y);
		std::cout << "Unable to find " << name << ". Look again at object name." << std::endl;
		return Object::Initialize(x,y);
	}
}
