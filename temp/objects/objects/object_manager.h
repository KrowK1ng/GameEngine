#include "gengine.h"
#include "objects/object_control.h"

namespace object{
	Object* CreateObect(const char* name, int x, int y){
		if (name == "ObjectControl") return new ObjectControl(x,y);
	}
}
