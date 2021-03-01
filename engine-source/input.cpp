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
	InputMouse::Instance();
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
	InputMouse::Instance()->Update();
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

InputMouse* InputMouse::sInstance = nullptr;

InputMouse* InputMouse::Instance(){
	if(!sInstance)
		sInstance = new InputMouse();
	return sInstance;
}

InputMouse::InputMouse()
	: x(0), y(0)
{
	MouseButtonState[0] = up;
	MouseButtonState[1] = up;
	MouseButtonState[2] = up;
}

void InputMouse::Update(){
	for(int i = 0; i < 3; i++){
		if(MouseButtonState[i] == pressed){
			MouseButtonState[i] = constant;
		}else if(MouseButtonState[i] == released){
			MouseButtonState[i] = up;
		}
	}
}

int InputMouse::GetState(MButtons button){
	return sInstance->MouseButtonState[button];
}

bool InputMouse::GetPressed(MButtons button){
	return (sInstance->MouseButtonState[button] == pressed);
}

bool InputMouse::GetReleased(MButtons button){
	return (sInstance->MouseButtonState[button] == released);
}
