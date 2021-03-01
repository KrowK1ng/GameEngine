#ifndef OBJECT_CONTROL_H
#define OBJECT_CONTROL_H
//#include "../../engine-source/object.h"
#include "object.h"

class ObjectControl : public Object{
	
	public:
		ObjectControl(int _x, int _y);
		~ObjectControl();
		void Start();
		void Step();
		void Draw();
		enum ChessPiece{
			nothing = 0,
			wPawn,
			wRock,
			wQueen,
			wHorse,
			wBishop,
			wKing,
			bPawn,
			bRock,
			bQueen,
			bHorse,
			bBishop,
			bKing
		};
		void StartBoard();
		void RenderPeace(ChessPiece _id, int _x, int _y);


		ChessPiece table[8][8];
		int l, cellsize;
		Sprite* WhiteSquare;
		Sprite* BlackSquare;
		Sprite* swPawn;
		Sprite* swRock;
		Sprite* swQueen;
		Sprite* swHorse;
		Sprite* swBishop;
		Sprite* swKing;
		Sprite* sbPawn;
		Sprite* sbRock;
		Sprite* sbQueen;
		Sprite* sbHorse;
		Sprite* sbBishop;
		Sprite* sbKing;
};

#endif
