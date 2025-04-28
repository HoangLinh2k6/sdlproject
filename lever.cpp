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
#include "ball.h"
#include "block.h"
#include "lever.h"

Lever::Lever( window& _win):
    win { _win },
    background{ win.renderer,BACKGROUND },
    ball{ win.renderer,BALL_IMAGE }
{}

void Lever::event(){
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if ( e.type == SDL_QUIT ) endgame = true;
        else if( e.type == SDL_KEYDOWN){
            if( e.key.keysym.scancode == SDL_SCANCODE_UP ) { ball.up(); }
            if( e.key.keysym.scancode == SDL_SCANCODE_DOWN ) { ball.down(); }
            if( e.key.keysym.scancode == SDL_SCANCODE_SPACE ) { ball.Jump() ; }
            if( e.key.keysym.scancode == SDL_SCANCODE_E ) { ball.useEnergy(); }
        }
    }
}

void Lever::logic(){
    background.scroll(scroll);
    ball.doJump();
    int RandomNum = std::rand();
    if( RandomNum % abc == 0 ){
        block.push_back(createBlock(win.renderer,BALL_IMAGE));
        abc = 10;
    }
    if( abc > 1){ abc --;}
    blockSize = block.size();

    for( int i = 0; i < blockSize; i++ ){
        block[i].scroll(scroll);
        endgame = ( endgame || block[i].checkCollision(ball) );
    }

}

void Lever::render(){
    background.render();
    ball.render();
    for( int i = 0; i < blockSize; i++ ){
        block[i].render();
    }
    win.update();
}

void Lever::deleteBlock(){
    while( !block.empty() && block[0].x < 0){
        block[0].quit();
        block.erase(block.begin());
    }
}

void Lever::quit(){
    ball.quit();
    background.quit();
}
