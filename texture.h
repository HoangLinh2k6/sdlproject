#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>

struct Texture{
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int w, h;
    void setRenderer( SDL_Renderer *_renderer );
    void loadTexture(const char *filename);

    int get_w();
    int get_h();

    void render( int x, int y, int angle = 0);

    void free();
};
#endif // TEXTURE_H
