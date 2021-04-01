#ifndef AUDIO_H
#define AUDIO_H
#include "gamelibs.h"

class Sound{
	public:
		Sound(const char* _source);
		~Sound();
		virtual void Play(int _n);
		//Add more functions

		Mix_Chunk* sound;
};

#endif
