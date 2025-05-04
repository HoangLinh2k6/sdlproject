#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>
#include "defs.h"

struct Music{
    Mix_Music *music;
    Music();

    void play();
    void quit();

};

struct Sound{
    Mix_Chunk* chunk;
    Sound();

    void play();
    void quit();

};

#endif // SOUND_H
