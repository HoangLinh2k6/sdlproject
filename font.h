#ifndef FONT_H
#define FONT_H

#include <SDL.h>
#include <SDL_ttf.h>


struct Font {
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Color color;
    SDL_Texture *texture ;

    Font( SDL_Renderer* ren, const char* text, int _size );

    void createTexture( const char* text );
    void render( int x, int y );
    void free();
};

#endif // FONT_H
