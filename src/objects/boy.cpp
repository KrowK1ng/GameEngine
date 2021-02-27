#include "boy.h"
#include "engine.h"

Boy::Boy(int _x, int _y)
	: Object(_x,_y)
{}

void Boy::Start(){
	l = 0;
	iq = 10;
}

void Boy::Step(){
	l++;
	l = l % (3 * engine::GetFPS());
	if(!l){
		iq++;
		std::cout << "Yay My IQ is " << iq << "\n";
	}
	if(iq > 15)
		engine::ChangeRoom("room0");
}

void Boy::Draw(){

}
