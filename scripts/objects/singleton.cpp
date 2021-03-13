#include "PLACE_HOLDER_FILE_NAME.h"

PLACE_HOLDER_CLASS::PLACE_HOLDER_CLASS(int _x, int _y)
	: Object(_x, _y)
{
	Start();
}

PLACE_HOLDER_CLASS::~PLACE_HOLDER_CLASS(){

}

PLACE_HOLDER_CLASS* PLACE_HOLDER_CLASS::sInstance = NULL;

PLACE_HOLDER_CLASS* PLACE_HOLDER_CLASS::Initialize(int _x, int _y){
	if(sInstance == NULL)
		sInstance = new PLACE_HOLDER_CLASS(_x, _y);
	return sInstance;
}

PLACE_HOLDER_CLASS* PLACE_HOLDER_CLASS::Instance(){
	return sInstance;
}

void PLACE_HOLDER_CLASS::Start(){

}

void PLACE_HOLDER_CLASS::Step(){

}

void PLACE_HOLDER_CLASS::Draw(){

}

void PLACE_HOLDER_CLASS::Destroy(){
	delete this;
}
