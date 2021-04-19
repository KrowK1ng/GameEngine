#ifndef GAME_ENGINE_START_H
#define GAME_ENGINE_START_H

#include "gamelibs.h"
#include "game.h"
#include "objects/object_manager.h"
#include "object.h"

namespace engine{
	void StartGame(char* title, int fps, int screen_w, int screen_h, int scale, bool fullscreen);
	void ChangeRoom(std::string relative_path);
	void EndGame();
	void EngineStep();


	int GetFPS();

	//Input
	bool GetKey(SDL_Scancode scanCode);
	bool GetKeyPressed(SDL_Scancode scanCode);
	bool GetKeyReleased(SDL_Scancode scanCode);
	///Mouse
	bool GetMButtonPressed(int button);
	bool GetMButtonReleased(int button);
	int GetMouseX();
	int GetMouseY();
	
	List<Object*>::node* CreateObject(std::string _name, int _x, int _y);
	void DestroyObject(List<Object*>::node*  _id);

	//Collision
	bool GetCollAABB(Collider* _colA, Collider* _colB);
	bool GetCollToPoint(Collider* _coll, int _x, int _y);

	//Rendering
	int GetViewX();
	int GetViewY();
	int GetViewW();
	int GetViewH();
	void SetView(int _x, int _y);
	void SetViewClean(int _x, int _y);
	void SetViewCenter(int _x, int _y);
	void SetFullscreen();

	//Drawing
	void DrawSetColor(int _depth, Uint8 r, Uint8 g, Uint8 b);
	void DrawRectangle(int _depth, int _x, int _y, int _w, int _h);
	void DrawText(int _depth, int _x, int _y, TTF_Font* _font, std::string _text, Uint8 _r, Uint8 _g, Uint8 _b);
	void DrawTextExt(int _depth, int _x, int _y, int _halign, int _valign, TTF_Font *_font, std::string _text, Uint8 _r, Uint8 _g, Uint8 _b);
	void DrawTextTran(int _depth, int _x, int _y, int _width, TTF_Font *_font, std::string _text, Uint8 _r, Uint8 _g, Uint8 _b);
	void DrawTextTranExt(int _depth, int _x, int _y, int _width, int _halign, int _valign, TTF_Font *_font, std::string _text, Uint8 _r, Uint8 _g, Uint8 _b);

	//Math
	float GetAngle2Points(int _x1, int _y1, int _x2, int _y2);
	bool PointOutsideRoom(int _x, int _y);
};

#endif
