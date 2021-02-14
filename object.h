#ifndef OBJECT_H
#define OBJECT_H
#include "sprite.h"
#include "gamelibs.h"

class ObjectManager;
class Object;

class ObjectManager{
	
	public:
		ObjectManager();
		~ObjectManager();
		struct onode{					//Node of an object
			Object* object;
			onode* prev = nullptr;
			onode* next = nullptr;
		}* hnode,* lastnode,* tempnode;
		void AddObject(Object* _point);
		void DestroyObject(onode* _id);
		void Step();
		void Draw();
};

class Object{
	
	public:
		Object(int _x, int _y);
		void AddSprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff);
		virtual void Start();
		virtual void Step();
		virtual void Draw();

		int x, y, depth;
		ObjectManager::onode* id;
		Sprite* sprite = nullptr; 

};
#endif
