#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>

#include "texture.h"
#include "exception.h"

struct Background {
    Texture texture;
    int scrollingOffset = 0;
    Background( SDL_Renderer *renderer, const char *filename ) {
        texture.setRenderer(renderer);
        texture.loadTexture(filename);
    }

    void scroll(int distance) {
        scrollingOffset -= distance;
        if( scrollingOffset < 0 ) { scrollingOffset = texture.w; }
    }

    void render() {
        texture.render( scrollingOffset, 0);
        texture.render( scrollingOffset - texture.w, 0);
    }
    void quit() {
        texture.free();
    }


};

#endif // BACKGROUND_H
