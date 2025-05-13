#include <cstdlib>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>

#include "window.h"
#include "lever.h"
#include "lost.h"
#include "menu.h"
#include "highscore.h"
#include "game.h"
#include "sound.h"

Game menu( window& win ){
    Menu menu( win );

    while( menu.game == Game::Menu ){
        menu.render();
        menu.event();
    }

    menu.quit();
    return menu.game;
}
Game lever( window& win, int& score ){
    Lever lever( win );

    while( !lever.endgame ){
        lever.event();
        lever.logic();
        lever.render();
        lever.deleteBlock();
        lever.gameSpeed();

        SDL_Delay( lever.delay );
    }
    score = lever.getNewScore();
    lever.quit();
    return Game::Lost;
}

Game lost( window& win, int& score ){
    Lost lost( win );
    lost.setScore( score );
    while( lost.game == Game::Lost ){
        lost.render();
        lost.event();
    }

    lost.quit();
    return lost.game;
}

Game highScore( window& win ){
    HighScore highScore( win );

    while( highScore.game == Game::HighScore ){
        highScore.render();
        highScore.event();
    }

    highScore.quit();
    return highScore.game;
}

int main( int argc , char* argv[] ){
    window win;
    win.init();
    Music music;
    music.play();
    int score;
    std::srand(std::time(nullptr));
    Game game = Game::Menu;
    while( game != Game::EndGame ){
        switch( game ){
            case Game::Menu     : game = menu     ( win );        break;
            case Game::HighScore: game = highScore( win );        break;
            case Game::Level    : game = lever    ( win, score ); break;
            case Game::Lost     : game = lost     ( win, score ); break;
        }
    }
    music.quit();
    win.quit();
    return 0;
}
