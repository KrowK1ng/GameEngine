#ifndef CHESS_HANDLER_H
#define CHESS_HANDLER_H

//GAME-ENGINE-IGNORE

class ChessHandler {
	public:
		ChessHandler(int _x, int _y);
		~ChessHandler();
		enum GameStates{
			idle,		//Before choosing the peace
			choosed		//The piece was choosed

		};
		enum PieceType{
			pawn,
			rock,
			queen,
			horse,
			bishop,
			king
		};
		enum MoveType{
			none,
			go,
			attack
		};
		void Step();
		void Draw();
		GameStates state;
		PieceType selPiece;
		bool isWhite;
		int selx, sely;
		int cellsize;
	private:
		void DoBoard();
		bool isEnemy(int _x, int _y);
		bool canGo(int _x, int _y);
		void MakeCell(int _x, int _y);
		MoveType Board[8][8];
};

#endif
