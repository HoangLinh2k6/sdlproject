#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

struct window{
    SDL_Renderer *renderer;
	SDL_Window *window;
    void init();
    void quit();
    void update();

};
#endif // WINDOW_H
