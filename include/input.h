#ifndef INPUT_H
#define INPUT_H

#include "gamelibs.h"

class Input{
	private:
		static Input* sInstance;
		const Uint8* KeyboardState;
	public:
		static Input* Instance();
		bool KeyDown(SDL_Scancode scanCode);
		int ComplexKey(SDL_Scancode scanCode);
		bool KeyPressed(SDL_Scancode scanCode);
		bool KeyReleased(SDL_Scancode scanCode);
		void Update();
		~Input();
		enum KStates{
			up,
			released,
			pressed,
			constant
		};
	private:
		Input();
		KStates LastKeyboardState[200];
};

#endif
