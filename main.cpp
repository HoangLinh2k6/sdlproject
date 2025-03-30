#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "background.h"
#include "texture.h"
#include "window.h"

int main( int argc , char* argv[] ){
    window win;
    win.init();
    bool quit = false;
    SDL_Event event;
    while ( !quit ){
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }
    }
    win.quit();
    return 0;
}
