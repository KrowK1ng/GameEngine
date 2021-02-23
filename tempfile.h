#include "gengine.h"
#include "objects/enemis/enemy.h"
#include "objects/object_control.h"

namespace object{
	Object* CreateObect(const char* name, int x, int y){
		if (name == "GoodEnemy") return new GoodEnemy(x,y);
		if (name == "BadEnemy") return new BadEnemy(x,y);
		if (name == "ObjectControl") return new ObjectControl(x,y);
		}
	}
}
