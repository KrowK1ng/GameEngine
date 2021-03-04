#include "chess_handler.h"
#include "object_control.h"
#include "engine.h"

ChessHandler::ChessHandler()
	: state(idle), selx(0), sely(0), isWhite(true), cellsize(32)
{
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			Board[i][j] = none;
		}
	}
}

void ChessHandler::Step(){
	if(!engine::GetMButtonPressed(0))
		return;
	int pressx = engine::GetMouseX() / cellsize;
	int pressy = engine::GetMouseY() / cellsize;
	if(pressx > 7) pressx = 7;
	if(pressy > 7) pressy = 7;
	if(state == idle){
		if(ObjectControl::Instance()->table[pressx][pressy] == ObjectControl::ChessPiece::nothing)
			return;
		if(isWhite){
			if(isEnemy(pressx, pressy))
				return;
			selx = pressx;
			sely = pressy;
			state = choosed;
			selPiece = static_cast<PieceType>(ObjectControl::Instance()->table[pressx][pressy] - ObjectControl::ChessPiece::wPawn);
			DoBoard();
			return;
		}else{
			if(isEnemy(pressx, pressy))
				return;
			selx = pressx;
			sely = pressy;
			state = choosed;
			selPiece = static_cast<PieceType>(ObjectControl::Instance()->table[pressx][pressy] - ObjectControl::ChessPiece::bPawn);
			DoBoard();
			return;
		}
	}else if(state == choosed){
		if(Board[pressx][pressy] != none){
			ObjectControl::Instance()->table[pressx][pressy] = ObjectControl::Instance()->table[selx][sely];
			ObjectControl::Instance()->table[selx][sely] = ObjectControl::ChessPiece::nothing;
			isWhite = !isWhite;
		}
		state = idle;
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				Board[i][j] = none;
			}
		}
	}
}

void ChessHandler::Draw(){
	if(state == idle)
		return;
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(Board[i][j] == go)
				ObjectControl::Instance()->DrawGreen(i, j);
			if(Board[i][j] == attack)
				ObjectControl::Instance()->DrawRed(i, j);
		}
	}
	//ObjectControl::Instance()->DrawGreen(selx, sely);
}

void ChessHandler::DoBoard(){
	int i, j;
	switch (selPiece) {
		case pawn:
			if (isWhite) {
				if(!ObjectControl::Instance()->table[selx][sely - 1])
					MakeCell(selx, sely - 1);
				if(ObjectControl::Instance()->table[selx + 1][sely - 1])
					MakeCell(selx + 1, sely - 1);
				if(ObjectControl::Instance()->table[selx - 1][sely - 1])
					MakeCell(selx - 1, sely - 1);
				if(sely == 6 && !ObjectControl::Instance()->table[selx][sely - 2])
					MakeCell(selx, sely - 2);
			}else{
				if(!ObjectControl::Instance()->table[selx][sely + 1])
					MakeCell(selx, sely + 1);
				if(ObjectControl::Instance()->table[selx + 1][sely + 1])
					MakeCell(selx + 1, sely + 1);
				if(ObjectControl::Instance()->table[selx - 1][sely + 1])
					MakeCell(selx - 1, sely + 1);
				if(sely == 1 && !ObjectControl::Instance()->table[selx][sely + 2])
					MakeCell(selx, sely + 2);
			}
			break;
		case rock:
			for(i = selx - 1; i > -1; i--){
				MakeCell(i, sely);
				if(ObjectControl::Instance()->table[i][sely])
					i = -1;
			}
			for(i = selx + 1; i < 8; i++){
				MakeCell(i, sely);
				if(ObjectControl::Instance()->table[i][sely])
					i = 8;
			}
			for(i = sely - 1; i > -1; i--){
				MakeCell(selx, i);
				if(ObjectControl::Instance()->table[selx][i])
					i = -1;
			}
			for(i = sely + 1; i < 8; i++){
				MakeCell(selx, i);
				if(ObjectControl::Instance()->table[selx][i])
					i = 8;
			}
			break;
		case queen:
			for(i = selx - 1; i > -1; i--){
				MakeCell(i, sely);
				if(ObjectControl::Instance()->table[i][sely])
					i = -1;
			}
			for(i = selx + 1; i < 8; i++){
				MakeCell(i, sely);
				if(ObjectControl::Instance()->table[i][sely])
					i = 8;
			}
			for(i = sely - 1; i > -1; i--){
				MakeCell(selx, i);
				if(ObjectControl::Instance()->table[selx][i])
					i = -1;
			}
			for(i = sely + 1; i < 8; i++){
				MakeCell(selx, i);
				if(ObjectControl::Instance()->table[selx][i])
					i = 8;
			}
		case bishop:
			for(i = selx - 1, j = sely - 1; i > -1 && j > -1; i--, j--){
				MakeCell(i,j);
				if(ObjectControl::Instance()->table[i][j])
					i = -1;
			}
			for(i = selx - 1, j = sely + 1; i > -1 && j < 8; i--, j++){
				MakeCell(i,j);
				if(ObjectControl::Instance()->table[i][j])
					i = -1;
			}
			for(i = selx + 1, j = sely - 1; i < 8 && j > -1; i++, j--){
				MakeCell(i,j);
				if(ObjectControl::Instance()->table[i][j])
					i = 8;
			}
			for(i = selx + 1, j = sely + 1; i < 8 && j < 8; i++, j++){
				MakeCell(i,j);
				if(ObjectControl::Instance()->table[i][j])
					i = 8;
			}
			break;
		case horse:
			MakeCell(selx + 1, sely + 2);
			MakeCell(selx + 1, sely - 2);
			MakeCell(selx - 1, sely + 2);
			MakeCell(selx - 1, sely - 2);
			MakeCell(selx + 2, sely + 1);
			MakeCell(selx + 2, sely - 1);
			MakeCell(selx - 2, sely + 1);
			MakeCell(selx - 2, sely - 1);
			break;
		case king:
			for(i = -1; i < 2; i++){
				for(j = -1; j < 2; j++){
					if(i || j)
						MakeCell(selx + i, sely + j);
				}
			}
			

	}

}

void ChessHandler::MakeCell(int _x, int _y){
	if(_x > 7 || _x < 0 || _y > 7 || _y < 0)
		return;

	if(canGo(_x, _y))
		Board[_x][_y] = go;
	if(isEnemy(_x, _y))
		Board[_x][_y] = attack;
}

bool ChessHandler::canGo(int _x, int _y){
	if(ObjectControl::Instance()->table[_x][_y] == ObjectControl::ChessPiece::nothing)
		return true;
	return isEnemy(_x, _y);
}

bool ChessHandler::isEnemy(int _x, int _y){
	if(!ObjectControl::Instance()->table[_x][_y])
		return false;

	if(isWhite){
			if(ObjectControl::Instance()->table[_x][_y] > ObjectControl::ChessPiece::wKing)
				return true;
	}else{
			if(ObjectControl::Instance()->table[_x][_y] < ObjectControl::ChessPiece::bPawn)
				return true;
	}
	return false;
}
