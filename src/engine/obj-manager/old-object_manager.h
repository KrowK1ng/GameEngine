#include "gengine.h"
//includes

namespace object{
	Object* CreateObject(std::string name, int x, int y){
		Object* obj;
		switch (name) {
			case "x":
				return new x(x , y);
				break;
		}
	}
}
