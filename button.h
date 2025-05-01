#ifndef BUTTON_H
#define BUTTON_H

#include "texture.h"
#include "font.h"

struct Button{
    Texture texture;
    Font font;
    int x, y, w, h;
    Button( SDL_Renderer *renderer, const char *filename, int _x, int _y, const char* text, int _size );

    void render();
    bool click( int _x, int _y );

    void quit();
};

#endif // BUTTON_H
