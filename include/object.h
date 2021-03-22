#ifndef OBJECT_H
#define OBJECT_H
#include "sprite.h"
#include "collision.h"
#include "gamelibs.h"
#include "mathlib.h"

class ObjectManager;
class Object;

class ObjectManager{
	private:
		List<Object*>::node* tempnode;
	public:
		ObjectManager();
		~ObjectManager();
		List<Object*> ObjectList;
		List<List<Object*>::node*> DestroyList;
		List<Object*>::node* AddObject(Object* _point);
		void DestroyObject(List<Object*>::node* _id);
		//void AddDestroyObject(List<Object*>::node* _id);
		void Step();
		void Draw();
		void Destroy();
};

class Object{
	public:
		Object(int _x, int _y);
		~Object();
		void AddSprite(const char* _source, int _w, int _h, int _x, int _y, int _xoff, int _yoff, int _scale);
		static Object* Initialize(int _x, int _y);
		virtual void Start();
		virtual void Step();
		virtual void Draw();
		virtual void Destroy();
		virtual void AddObejct();
		virtual void DestroyObject();

		static List<Object*>::node* GetHeadNode();

		int x, y, depth;
		List<Object*>::node* id;							//id
		Sprite* sprite = nullptr; 
		Collider* collider = nullptr;
	private:
		List<Object*>::node* snode;							//self node
		static List<Object*> ObjectList;

};
#endif
