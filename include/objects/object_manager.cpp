#include "object_manager.h"

namespace object{
	Object* CreateObject(std::string name, int x, int y){
		if (name == "ObjectControl") return new ObjectControl(x,y);
		if (name == "Boy") return new Boy(x,y);
		std::cout << "Unable to hui " << name << ". Look again at object name." << std::endl;
		return new Object(x,y);
	}
}
