#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "defs.h"
#include "background.h"
#include "texture.h"
#include "window.h"
#include "ball.h"

int main( int argc , char* argv[] ){
    window win;
    win.init();
    Background background(win.renderer,"image\\bikiniBottom.jpg");
    Ball ball( win.renderer,"image\\ball.png");

    bool quit = false, jump = false, energy = false;
    int roll = 0, a = 100, x = 100;
    SDL_Event event;
    while ( !quit ){
        background.scroll(50);
        background.render();

        while (SDL_PollEvent(&event)) {
            if ( event.type == SDL_QUIT ) quit = true;
            else if( event.type == SDL_KEYDOWN){
                if( event.key.keysym.scancode == SDL_SCANCODE_UP ) ball.up();
                if( event.key.keysym.scancode == SDL_SCANCODE_DOWN ) ball.down();
                if( event.key.keysym.scancode == SDL_SCANCODE_SPACE ) jump = true;
                if( event.key.keysym.scancode == SDL_SCANCODE_E ){
                    energy = true;
                    a = 0;
                }
            }
        }
        if( jump ) ball.jump( jump );
        ball.render(roll);
        if( roll < 360 ) roll +=60;
        else roll = 60;
        if(energy){
            a++;
            x = 50;
            if( a == 100){
                energy = false;
                x = 100;
            }
        }
        SDL_RenderPresent(win.renderer);
        SDL_Delay( x );

    }
    background.quit();
    win.quit();
    return 0;
}
