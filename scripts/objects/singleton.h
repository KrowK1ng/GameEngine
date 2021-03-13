#ifndef PLACE_HOLDER_DEFINE
#define PLACE_HOLDER_DEFINE
#include "object.h"

class PLACE_HOLDER_CLASS : public Object{
	private:
		static PLACE_HOLDER_CLASS* sInstance;
		PLACE_HOLDER_CLASS(int _x, int _y);
		~PLACE_HOLDER_CLASS();

	public:
		static PLACE_HOLDER_CLASS* Initialize(int _x, int _y);
		static PLACE_HOLDER_CLASS* Instance();
		void Start() override;
		void Step() override;
		void Draw() override;
		void Destroy() override;
};

#endif
