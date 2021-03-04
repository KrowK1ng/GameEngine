//#include "../engine-source/engine.h"
#include "engine.h"

int main(){
	std::cout << "start main" << std::endl;
	engine::StartGame( "Chess Super Cool", 60, 512, 512, false);
	std::cout << "ended main";
}
