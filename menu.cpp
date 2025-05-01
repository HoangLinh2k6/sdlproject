#include <SDL.h>

#include "menu.h"
#include "defs.h"
#include "background.h"
#include "window.h"
#include "game.h"
#include "button.h"

Menu::Menu( window& _win ):
    win{ _win},
    background{ win.renderer, BACKGROUND },
    playButton{ win.renderer, BUTTON_IMAGE, 300, 200, "Play", 40 },
    exitButton{ win.renderer, BUTTON_IMAGE, 300, 300, "Exit", 40 }
{}

void Menu::render(){
        background.render();
        playButton.render();
        exitButton.render();
        win.update();
}

void Menu::event(){
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

                    if( playButton.click( x, y ) ){
                        quit();
                        game = Game::Level;
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

void Menu::quit(){
    background.quit();
    playButton.quit();
    exitButton.quit();
}
