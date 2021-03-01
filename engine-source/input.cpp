#include "input.h"

Input* Input::sInstance = nullptr;

Input* Input::Instance(){
	if(!sInstance)
		sInstance = new Input();
	return sInstance;
}

Input::Input(){
	for(int i = 0;i < 200; i++){
		LastKeyboardState[i] = up;
	}
}

Input::~Input(){

}

bool Input::KeyDown(SDL_Scancode scanCode){
	return KeyboardState[scanCode];
}

void Input::Update(){
	KeyboardState = SDL_GetKeyboardState(NULL);
	for(int i = 0;i < SDL_SCANCODE_Z; i++){
		if(KeyDown(static_cast<SDL_Scancode>(i))){
			if(LastKeyboardState[i] < pressed){
				LastKeyboardState[i] = pressed;
			}else{
				LastKeyboardState[i] = constant;
			}
		}else{
			if(LastKeyboardState[i] > released){
				LastKeyboardState[i] = released;
			}else{
				LastKeyboardState[i] = up;
			}
		}
	}
}

int Input::ComplexKey(SDL_Scancode scanCode){
	return LastKeyboardState[scanCode];
}

bool Input::KeyPressed(SDL_Scancode scanCode){
	return (LastKeyboardState[scanCode] == pressed);
}

bool Input::KeyReleased(SDL_Scancode scanCode){
	return (LastKeyboardState[scanCode] == released);
}
