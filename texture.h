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


    void render( int x, int y, int a = 0)
    {
        SDL_Rect renderQuad = { x, y, width, height };
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
        SDL_RenderCopyEx( renderer, texture, NULL, &renderQuad, a, NULL, flip );

    }

    void free(){
        if( texture != nullptr ) {
            SDL_DestroyTexture( texture );
            texture = nullptr;
        }
    }
};
#endif // TEXTURE_H
