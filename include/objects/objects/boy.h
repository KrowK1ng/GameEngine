#ifndef BOY_H
#define BOY_H
//#include "../../engine-source/object.h"
#include "object.h"

class Boy : public Object{
	private:
		Boy(int _x, int _y);
		~Boy();
	public:
		static Boy* Initialize(int _x, int _y);
		void Start();
		void Step();
		void Draw();

		int iq;
		int l;
};

#endif
