#ifndef PLACE_HOLDER_DEFINE
#define PLACE_HOLDER_DEFINE
#include "object.h"

class PLACE_HOLDER_CLASS : public Object{
	private:
		PLACE_HOLDER_CLASS(int _x, int _y);
		~PLACE_HOLDER_CLASS();
		List<Object*>::node* snode;
		static List<Object*> ObjectList;
	public:
		static PLACE_HOLDER_CLASS* Initialize(int _x, int _y);
		void Start() override;
		void Step() override;
		void Draw() override;
		void Destroy() override;
		void AddObejct() override;
		void DestroyObject() override;
		static List<Object*>::node* GetHeadNode();
};

#endif
