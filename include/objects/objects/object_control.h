#ifndef OBJECT_CONTROL_H
#define OBJECT_CONTROL_H
//#include "../../engine-source/object.h"
#include "object.h"
#include "chess_handler.h"

class ObjectControl : public Object{
	private:
		static ObjectControl* sInstance;
		ObjectControl(int _x, int _y);
		~ObjectControl();
	public:
		static ObjectControl* Instance();
		static ObjectControl* Initialize(int _x, int _y);
		void Start();
		void Step();
		void Draw();
		void DrawGreen(int _x, int _y);
		void DrawRed(int _x, int _y);
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
		ChessHandler* ChessH;
		Sprite* WhiteSquare;
		Sprite* BlackSquare;
		Sprite* GreenSquare;
		Sprite* RedSquare;
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
