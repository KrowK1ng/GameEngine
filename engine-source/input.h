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

class InputMouse{
	private:
		static InputMouse* sInstance;
	public:
		static InputMouse* Instance();
		int x, y;
		enum MButtons{
			m_left = 0,
			m_middle,
			m_right,
			m_another
		};
		enum MBStates{
			up,
			released,
			pressed,
			constant
		};
		MBStates MouseButtonState[4];
		void Update();
		static int GetState(MButtons button);
		static bool GetPressed(MButtons button);
		static bool GetReleased(MButtons button);
	private:
		InputMouse();
};

#endif
