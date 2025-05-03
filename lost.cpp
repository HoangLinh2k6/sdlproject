#include<SDL.h>

#include "lost.h"
#include "defs.h"
#include "background.h"
#include "window.h"
#include "game.h"
#include "button.h"

Lost::Lost( window _win ):
    win{ _win},
    background{ win.renderer,BACKGROUND },
    highScore{ win.renderer, highScore.getHighScore(), 60},
    menuButton{ win.renderer, 300, 300, "Menu", 40 },
    exitButton{ win.renderer, 300, 400, "Exit", 40 }
{}

void Lost::render(){
    background.render();
    highScore.renderHighScore( 150, 100 );
    menuButton.render();
    exitButton.render();
    win.update();
}

void Lost::event(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        switch( e.type ){
            case SDL_QUIT:
                quit();
                game = Game::EndGame;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if( e.button.button == SDL_BUTTON_LEFT ){
                    int x, y;
                    SDL_GetMouseState( &x, &y );

                    if( menuButton.click( x, y ) ){
                        quit();
                        game = Game::Menu;
                    }
                    if( exitButton.click( x, y ) ){
                        quit();
                        game = Game::EndGame;
                    }
                }
                break;

            default: break;
        }
    }
}

void Lost::quit(){
    background.quit();
    highScore.quit();
    menuButton.quit();
    exitButton.quit();
}
