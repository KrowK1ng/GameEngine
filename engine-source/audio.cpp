#include "audio.h"

Sound::Sound(const char* _source){
	sound = Mix_LoadWAV(_source);
}

Sound::~Sound(){
	Mix_FreeChunk(sound);
}

void Sound::Play(int _n){
	Mix_PlayChannel(-1, sound, _n);
}
