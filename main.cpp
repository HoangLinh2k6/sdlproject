#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


#include "defs.h"
#include "background.h"
#include "texture.h"
#include "window.h"
#include "ball.h"
#include "block.h"

int main( int argc , char* argv[] ){
    window win;
    win.init();
    std::srand(std::time(nullptr));
    Background background(win.renderer,"image\\bikiniBottom.jpg");
    Ball ball( win.renderer,"image\\ball.png");
    std::vector<Block> block;
    bool quit = false, energy = false;
    int  a = 100, x = 100, scroll = 50, abc = 10;
    SDL_Event event;
    while ( !quit ){
        background.scroll(scroll);
        background.render();
        int RandomNum = std::rand();
        if( RandomNum % abc == 0 ){
            block.push_back(createBlock(win.renderer,"image\\ball.png"));
            abc = 10;
        }
        if( abc > 1){ abc --;}
        int blockSize = block.size();
        for( int i = 0; i < blockSize; i++ ){
            block[i].render();
            block[i].scroll(scroll);
            quit = (quit || block[i].checkCollision(ball));
        }
        while (SDL_PollEvent(&event)) {
            if ( event.type == SDL_QUIT ) quit = true;
            else if( event.type == SDL_KEYDOWN){
                if( event.key.keysym.scancode == SDL_SCANCODE_UP ) ball.up();
                if( event.key.keysym.scancode == SDL_SCANCODE_DOWN ) ball.down();
                if( event.key.keysym.scancode == SDL_SCANCODE_SPACE ) ball.Jump() ;
                if( event.key.keysym.scancode == SDL_SCANCODE_E ){
                    energy = true;
                    a = 0;
                }
            }
        }

        ball.doJump();
        ball.render();
        if(energy){
            a++;
            x = 50;
            if( a == 100){
                energy = false;
                x = 100;
            }
        }
        while( !block.empty() && block[0].x < 0){
            block[0].quit();
            block.erase(block.begin());
        }
        SDL_RenderPresent(win.renderer);
        SDL_Delay( x );

    }
    ball.quit();
    background.quit();
    win.quit();
    return 0;
}
