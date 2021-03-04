#include "engine.h"
#include "object_control.h"
//#include "objects/object_manager.h"

ObjectControl* ObjectControl::sInstance = NULL;

ObjectControl* ObjectControl::Instance(){
	return sInstance;
}

ObjectControl::ObjectControl(int _x, int _y)
	: Object(_x,_y)
{
	sInstance = this;
}

void ObjectControl::Start(){
	int scale = 4;
	WhiteSquare = new Sprite("assets/chess.png",16,16,0,16,0,0,scale);
	BlackSquare = new Sprite("assets/chess.png",16,16,0,0,0,0,scale);
	GreenSquare = new Sprite("assets/chess.png",16,16,16,0,0,0,scale);
	RedSquare = new Sprite("assets/chess.png",16,16,16,16,0,0,scale);
	swPawn = new Sprite("assets/peaces.png",16,16,0,0,0,0,scale);
	swRock = new Sprite("assets/peaces.png",16,16,16,0,0,0,scale);
	swQueen = new Sprite("assets/peaces.png",16,16,32,0,0,0,scale);
	swHorse = new Sprite("assets/peaces.png",16,16,0,16,0,0,scale);
	swBishop = new Sprite("assets/peaces.png",16,16,16,16,0,0,scale);
	swKing = new Sprite("assets/peaces.png",16,16,32,16,0,0,scale);
	sbPawn = new Sprite("assets/peaces.png",16,16,0,32,0,0,scale);
	sbRock = new Sprite("assets/peaces.png",16,16,16,32,0,0,scale);
	sbQueen = new Sprite("assets/peaces.png",16,16,32,32,0,0,scale);
	sbHorse = new Sprite("assets/peaces.png",16,16,0,48,0,0,scale);
	sbBishop = new Sprite("assets/peaces.png",16,16,16,48,0,0,scale);
	sbKing = new Sprite("assets/peaces.png",16,16,32,48,0,0,scale);
	l = 0;
	cellsize = scale * 16;
	ChessH = new ChessHandler(0, 0);
	ChessH->cellsize = cellsize;
	StartBoard();
}

void ObjectControl::Step(){
	//if(engine::GetMButtonPressed(1)){
	//	printf("%d %d", engine::GetMouseX(), engine::GetMouseY());
	//}
	if(engine::GetMButtonPressed(0)){
		//std::cout << "Cell: "<< engine::GetMouseX() / cellsize << " " << engine::GetMouseY() / cellsize<< "\n";
	}
	ChessH->Step();
}

void ObjectControl::Draw(){
	for(int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			if(( i + j ) % 2)
				WhiteSquare->Render(i * cellsize, j * cellsize);
			else
				BlackSquare->Render(i * cellsize, j * cellsize);
		}
	}
	ChessH->Draw();
	for(int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			if(table[i][j] > 0)
				RenderPeace(table[i][j], i * cellsize, j * cellsize);
		}
	}
}

void ObjectControl::DrawRed(int _x, int _y){
	RedSquare->Render(_x * cellsize, _y * cellsize);
}

void ObjectControl::DrawGreen(int _x, int _y){
	GreenSquare->Render(_x * cellsize, _y * cellsize);
}

void ObjectControl::RenderPeace(ChessPiece _id, int _x, int _y){
	switch(_id){
		case wPawn:
			swPawn->Render(_x,_y);
			break;
		case wRock:
			swRock->Render(_x,_y);
			break;
		case wQueen:
			swQueen->Render(_x,_y);
			break;
		case wHorse:
			swHorse->Render(_x,_y);
			break;
		case wBishop:
			swBishop->Render(_x,_y);
			break;
		case wKing:
			swKing->Render(_x,_y);
			break;
		case bPawn:
			sbPawn->Render(_x,_y);
			break;
		case bRock:
			sbRock->Render(_x,_y);
			break;
		case bQueen:
			sbQueen->Render(_x,_y);
			break;
		case bHorse:
			sbHorse->Render(_x,_y);
			break;
		case bBishop:
			sbBishop->Render(_x,_y);
			break;
		case bKing:
			sbKing->Render(_x,_y);
			break;
		default:
			break;
	}
}

void ObjectControl::StartBoard(){
	for(int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			table[i][j] = nothing;
		}
	}

	// Pawns
	for(int i = 0; i < 8; i++){
		table[i][6] = wPawn;
		table[i][1] = bPawn;
	}

	// Rocks
	table[0][7] = wRock;
	table[7][7] = wRock;
	table[0][0] = bRock;
	table[7][0] = bRock;

	// Horses
	table[1][7] = wHorse;
	table[6][7] = wHorse;
	table[1][0] = bHorse;
	table[6][0] = bHorse;

	// Bishops
	table[2][7] = wBishop;
	table[5][7] = wBishop;
	table[2][0] = bBishop;
	table[5][0] = bBishop;
	
	//Queens
	table[3][7] = wQueen;
	table[3][0] = bQueen;

	//Kings
	table[4][7] = wKing;
	table[4][0] = bKing;
	/*for(int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			std::cout << table[i][j] << " ";
		}
		std::cout << "\n";
	}*/
}
