#include "highscore.h"
#include "background.h"
#include "button.h"
#include "score.h"
#include "window.h"
#include "game.h"
#include "defs.h"

HighScore::HighScore( window _win ):
    win{ _win },
    background{ win.renderer, BACKGROUND },
    deleteHighScoreButton{ win.renderer, 300, 400, "Delete", 35 },
    quitButton{ win.renderer, 300, 500, "Quit", 40 },
    highScore{ win.renderer, highScore.getHighScore(), 60 },
    game{ Game::HighScore }
{}

void HighScore::render(){
    background.render();
    highScore.renderHighScore( 150 , 200 );
    quitButton.render();
    if( highScore.highScore != 0 )deleteHighScoreButton.render();
    win.update();
}

void HighScore::event(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        switch( e.type ){
            case SDL_QUIT:
                game = Game::EndGame;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if( e.button.button == SDL_BUTTON_LEFT ){
                    int x, y;
                    SDL_GetMouseState( &x, &y );

                    if( quitButton.click( x, y ) ){
                        game = Game::Menu;
                    }
                    if( deleteHighScoreButton.click( x, y ) ){
                        highScore.resetHighScore();
                    }
                break;
                }
            default: break;
        }
    }
}

void HighScore::quit(){
    highScore.quit();
    background.quit();
    quitButton.quit();
    deleteHighScoreButton.quit();
}
