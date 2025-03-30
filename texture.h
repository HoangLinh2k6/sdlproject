#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include "exception.h"
struct Texture{
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int width, height;
    void setRenderer( SDL_Renderer *_renderer ){
        renderer = _renderer;
    }
    void loadTexture(const char *filename)
    {

        texture = IMG_LoadTexture(renderer, filename);
        if (texture == nullptr)
            logErrorAndExit( "Load texture %s", IMG_GetError());
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }


    void render( int x, int y)
    {
        SDL_Rect dest;


        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

        SDL_RenderCopy(renderer, texture, NULL, &dest);

    }

    void free(){
        if( texture != nullptr ) {
            SDL_DestroyTexture( texture );
            texture = nullptr;
        }
    }
};
#endif // TEXTURE_H
