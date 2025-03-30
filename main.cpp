#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "defs.h"
#include "background.h"
#include "texture.h"
#include "window.h"

int main( int argc , char* argv[] ){
    window win;
    win.init();
    Background background(win.renderer,"image//bikiniBottom.jpg");

    bool quit = false;
    SDL_Event event;
    while ( !quit ){
        background.scroll(10);
        background.render();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }
        SDL_RenderPresent(win.renderer);
        SDL_Delay(100);
    }
    background.quit();
    win.quit();
    return 0;
}
