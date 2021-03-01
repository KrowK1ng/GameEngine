#ifndef CHESS_HANDLER_H
#define CHESS_HANDLER_H
#include "object_control.h"

class ChessHandler {
	void DrawMove(ObjectControl::ChessPiece piece, ObjectControl::ChessPiece table, int x, int y);
};
#endif
