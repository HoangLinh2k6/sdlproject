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
#include "energy.h"
#include "lever.h"

Lever::Lever( window& _win):
    win { _win },
    background{ win.renderer,BACKGROUND },
    ball{ win.renderer,BALL_IMAGE },
    energy{ win.renderer },
    score{ win.renderer, score.getScore(), 20}
{}

void Lever::event(){
    SDL_Event e;
    while( SDL_PollEvent(&e) ){
        switch( e.type ){
            case SDL_QUIT: endgame = true; break;

            case SDL_KEYDOWN:
                switch( e.key.keysym.scancode ){
                    case SDL_SCANCODE_UP:    ball.up();    break;
                    case SDL_SCANCODE_DOWN:  ball.down();  break;
                    case SDL_SCANCODE_SPACE: ball.Jump();  break;
                    case SDL_SCANCODE_E:     energy.use(); break;

                    default: break;
                }
                break;

            default: break;
        }
    }
}

void Lever::logic(){
    background.scroll(scroll);
    score.updateScore();
    score.updateHighScore();
    ball.doJump();
    energy.updateEnergy();
    int RandomNum = std::rand();
    if( time == 7){
        if( RandomNum % 6 == 5 ){
            for( int lane = -1; lane < 2; lane++){
                block.push_back( createBlock( win.renderer, STONE_IMAGE, lane ) );
            }
        }
        else if( RandomNum % 6 == 3 || RandomNum % 6 == 1){
            int lane = std::rand() % 3 ;
            if( lane == 0 ){
                block.push_back( createBlock( win.renderer, STONE_IMAGE, -1 ) );
                block.push_back( createBlock( win.renderer, STONE_IMAGE, 0 ) );
            }
            if( lane == 1 ){
                block.push_back( createBlock( win.renderer, STONE_IMAGE, -1 ) );
                block.push_back( createBlock( win.renderer, STONE_IMAGE, 1 ) );
            }
            if( lane == 2 ){
                block.push_back( createBlock( win.renderer, STONE_IMAGE, 1 ) );
                block.push_back( createBlock( win.renderer, STONE_IMAGE, 0 ) );
            }
        }
        else {
            int lane = std::rand() % 3 - 1;
            block.push_back( createBlock( win.renderer, STONE_IMAGE, lane ) );
        }
    }
    time --;
    if( time == 0){ time = 7; }
    blockSize = block.size();

    for( int i = 0; i < blockSize; i++ ){
        block[i].scroll(scroll);
        endgame = ( endgame || block[i].checkCollision(ball) );
    }

}

void Lever::render(){
    background.render();
    energy.render();
    score.renderScore( 600, 50 );
    for( int i = 0; i < blockSize; i++ ){
        block[i].render();
    }
    ball.render();
    win.update();
}

void Lever::deleteBlock(){
    while( !block.empty() && block[0].x < 0){
        block[0].quit();
        block.erase(block.begin());
    }
}

void Lever::gameSpeed(){
    if( energy.useEnergy ) delay = 50;
    else delay = 100;
}

void Lever::quit(){
    ball.quit();
    background.quit();
}
