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
#include "lost.h"
#include "menu.h"
#include "game.h"
#include "button.h"
#include "score.h"

Game menu( window& win ){
    Menu menu( win );

    while( menu.game == Game::Menu ){
        menu.render();
        menu.event();
    }
    menu.quit();
    return menu.game;
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
    Lost lost( win );

    while( lost.game == Game::Lost ){
        lost.render();
        lost.event();
    }
    lost.quit();
    return lost.game;
}

Game highScore( window& win ){
    Background background( win.renderer, BACKGROUND );
    Button deleteHighScoreButton( win.renderer, 300, 400, "Delete", 35 );
    Button quitButton( win.renderer, 300, 500, "Quit", 40 );
    Score highScore( win.renderer, highScore.getHighScore(), 60 );
    background.render();
    highScore.renderHighScore( 150 , 200 );
    quitButton.render();
    if( highScore.highScore != 0 )deleteHighScoreButton.render();
    win.update();
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        switch( e.type ){
            case SDL_QUIT:
                highScore.quit();
                background.quit();
                quitButton.quit();
                deleteHighScoreButton.quit();
                return Game::EndGame;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if( e.button.button == SDL_BUTTON_LEFT ){
                    int x, y;
                    SDL_GetMouseState( &x, &y );

                    if( quitButton.click( x, y ) ){
                        highScore.quit();
                        background.quit();
                        quitButton.quit();
                        deleteHighScoreButton.quit();
                        return Game::Menu;
                    }
                    if( deleteHighScoreButton.click( x, y ) ){
                        highScore.resetHighScore();
                    }
                break;
                }
            default: break;
        }
    }
    highScore.quit();
    background.quit();
    quitButton.quit();
    deleteHighScoreButton.quit();
    return Game::HighScore;
}

int main( int argc , char* argv[] ){
    window win;
    win.init();
    std::srand(std::time(nullptr));
    Game game = Game::Menu;
    while( game != Game::EndGame ){
        switch( game ){
            case Game::Menu     : game = menu     ( win ); break;
            case Game::HighScore: game = highScore( win ); break;
            case Game::Level    : game = lever    ( win ); break;
            case Game::Lost     : game = lost     ( win ); break;
        }
    }
    win.quit();
    return 0;
}
