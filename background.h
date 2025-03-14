#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "texture.h"

/*struct ScrollingBackground {
    SDL_Texture* texture;
    int scrollingOffset = 0;
    int width, height;

    void setTexture(SDL_Texture* _texture) {
        texture = _texture;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }

    void scroll(int distance) {
        scrollingOffset -= distance;
        if( scrollingOffset < 0 ) { scrollingOffset = width; }
    }

    void render() {
        renderTexture(texture, scrollingOffset, 0);
        renderTexture(texture, scrollingOffset - width, 0);
    }
};*/

#endif // BACKGROUND_H
