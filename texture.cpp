#include "texture.h"

#include "defs.h"

Texture::Texture( SDL_Renderer *_renderer, const char *filename):
    renderer { _renderer },
    texture { IMG_LoadTexture(renderer, filename) }
    {
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    }

int Texture::get_w(){
    return w;
}
int Texture::get_h(){
    return h;
}
void Texture::render( int x, int y, int angle )
{
    SDL_Rect renderQuad = { x, y, w, h };
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx( renderer, texture, NULL, &renderQuad, angle, NULL, flip );

}

void Texture::free(){
    if( texture != nullptr ) {
        SDL_DestroyTexture( texture );
        texture = nullptr;
    }
}
