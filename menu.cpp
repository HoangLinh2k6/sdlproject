#include <SDL.h>

#include "menu.h"
#include "defs.h"
#include "background.h"
#include "window.h"
#include "game.h"
#include "button.h"

Menu::Menu( window& _win ):
    win{ _win},
    background      { win.renderer, BACKGROUND },
    playButton      { win.renderer, 300, 200, "Play", 40 },
    highScoreButton { win.renderer, 300, 300, "HighScore", 20 },
    exitButton      { win.renderer, 300, 400, "Exit", 40 }
{}

void Menu::render(){
        background.render();
        playButton.render();
        highScoreButton.render();
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
                    if( highScoreButton.click( x, y ) ){
                        quit();
                        game = Game::HighScore;
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
    highScoreButton.quit();
    exitButton.quit();
}
