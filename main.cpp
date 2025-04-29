#include <cstdlib>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>


#include "defs.h"
#include "background.h"
#include "window.h"
#include "lever.h"
#include "game.h"

Game intro( window& win ){
    Background background( win.renderer,BACKGROUND );
    while(true){
        SDL_Event e;
        background.render();
        win.update();
        while (SDL_PollEvent(&e)) {
            if ( e.type == SDL_QUIT ){
                background.quit();
                return Game::EndGame ;
            }
            else if( e.type == SDL_KEYDOWN){
                if( e.key.keysym.scancode == SDL_SCANCODE_SPACE ){
                        background.quit();
                        return Game::Level ;
                }
            }
        }
    }
}
Game lever( window& win ){
    Lever lever( win );
    while( !lever.endgame ){
        lever.event();
        lever.logic();
        lever.render();
        lever.deleteBlock();
        lever.gameSpeed();

        SDL_Delay( lever.delay );
    }
    lever.quit();
    return Game::Lost;
}

Game lost( window& win ){
    Background background( win.renderer,BACKGROUND );
    while(true){
        SDL_Event e;
        background.render();
        win.update();
        while (SDL_PollEvent(&e)) {
            if ( e.type == SDL_QUIT ){
                background.quit();
                return Game::EndGame ;
            }
            else if( e.type == SDL_KEYDOWN){
                if( e.key.keysym.scancode == SDL_SCANCODE_RETURN ){
                        background.quit();
                        return Game::Intro;
                }
            }
        }
    }
}

int main( int argc , char* argv[] ){
    window win;
    win.init();
    std::srand(std::time(nullptr));
    Game game = Game::Intro;
    while( game != Game::EndGame ){
        switch( game ){
            case Game::Intro : game = intro( win); break;
            case Game::Level : game = lever( win ); break;
            case Game::Lost  : game = lost( win ); break;
        }
    }
    win.quit();
    return 0;
}
