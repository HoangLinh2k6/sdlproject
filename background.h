#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>

#include "texture.h"

struct Background {
    Texture texture;
    int scrollingOffset = 0;
    Background( SDL_Renderer *renderer, const char *filename );

    void scroll(int distance);
    void render();
    void quit();
};

#endif // BACKGROUND_H
