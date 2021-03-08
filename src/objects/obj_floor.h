#ifndef OBJ_FLOOR_H
#define OBJ_FLOOR_H
#include "object.h"

class Floor : public Object{
	private:
		Floor(int _x, int _y);
		~Floor();
		onode* snode;
		static onode* hnode, *lastnode;
	public:
		static Floor* Initialize(int _x, int _y);
		void Start() override;
		void Step() override;
		void Draw() override;
		void AddObejct() override;
		void DestroyObject() override;
		static onode* GetHeadNode();
		
		Sprite* Tile;
};

#endif
