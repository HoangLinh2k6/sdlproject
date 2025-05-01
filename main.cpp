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

int main( int argc , char* argv[] ){
    window win;
    win.init();
    std::srand(std::time(nullptr));
    Game game = Game::Menu;
    while( game != Game::EndGame ){
        switch( game ){
            case Game::Menu  : game = menu ( win ); break;
            case Game::Level : game = lever( win ); break;
            case Game::Lost  : game = lost ( win ); break;
        }
    }
    win.quit();
    return 0;
}
