#ifndef RENDERER_H
#define RENDERER_H
#include "gamelibs.h"
#include "mathlib.h"

class Renderer;
class RenderObject;


class Renderer {
	public:
		Renderer();
		int CreateWindow(char* _title, int _xpos, int _ypos, int _width, int _height, bool _fullscreen);
		void RenderStart();
		void RenderWindow();
		void AddRenderObject(RenderObject* _obj);
		void CloseWindow();
		void AddSpriteToRender(int _depth,bool _isComp, SDL_Texture* _tex, SDL_Rect* _sRect, SDL_Rect* _dRect, double _ang, SDL_Point* _offset, SDL_RendererFlip _flip);
		void AddRectToRender(int _depth, int _x, int _y, int _w, int _h, int _r, int _g, int _b);
		//static void Render();
		static SDL_Renderer* renderer;
		static Renderer* self;
		int xView, yView, hView, wView;
		int scale;
		SDL_Window* window;
	private :
		/*struct RenderObj{
			RenderObject* rObj = nullptr;
			int depth;
		}* hnode,* tempnode,* prevnode;*/
		List<RenderObject*> RenderList;
};

class RenderObject {
	public:
		RenderObject(){}
		~RenderObject(){}
		virtual void draw(){}
		int depth;
};

class RenderSprite : public RenderObject {
	public:
		RenderSprite(bool _isComp, SDL_Texture* _tex, SDL_Rect* _sRect, SDL_Rect _dRect, double _ang, SDL_Point* _offset, SDL_RendererFlip _flip);
		~RenderSprite(){
			delete &dRect;
		}
		void draw() override{
			if(isComplex){
				SDL_RenderCopyEx(Renderer::renderer, texture, sRect, &dRect, angle, offset, flipFlag);
				return;
			}
			SDL_RenderCopy(Renderer::renderer, texture, sRect, &dRect);
			return;
		}
	private:
		bool isComplex;
		SDL_Point *offset;
		SDL_Texture* texture;
		SDL_Rect* sRect;
		SDL_Rect dRect;
		double angle;
		SDL_RendererFlip flipFlag;
};

class RenderRectangle : public RenderObject {
	public:
		RenderRectangle(int _x, int _y, int _w, int _h, int _r, int _g, int _b);
		~RenderRectangle(){
			delete rect;
		}
		void draw() override{
			//Temp
			SDL_SetRenderDrawColor(Renderer::renderer, r, g, b, 255);
			SDL_RenderFillRect(Renderer::renderer, rect);
		}
	private:
		SDL_Rect* rect;
		int r, g, b;
};

#endif
