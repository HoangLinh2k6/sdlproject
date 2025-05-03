#include <SDL.h>
#include <SDL_ttf.h>

#include "defs.h"
#include "font.h"

Font::Font( SDL_Renderer* ren, const char* text, int _size ):
    renderer{ ren },
    font{ TTF_OpenFont( FONT, _size ) },
    color{ 0, 0, 0, 255 }
{
    createTexture( text );
}

void Font::createTexture( const char* text ){

    SDL_Surface* textSurface = TTF_RenderText_Solid( font, text, color );

    if (!textSurface){
        SDL_Log("Failed to render text surface: %s", TTF_GetError());
        SDL_FreeSurface( textSurface );
        return;
    }

    texture = SDL_CreateTextureFromSurface( renderer, textSurface );

    if (!texture){
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
        SDL_FreeSurface( textSurface );
        return;
    }

    SDL_FreeSurface( textSurface );
}

void Font::render( int x, int y ){
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Font::free(){
    SDL_DestroyTexture(texture);
    texture = nullptr;
    TTF_CloseFont(font);
    font = nullptr;
}
