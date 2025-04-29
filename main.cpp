#include <cstdlib>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


#include "defs.h"
#include "background.h"
#include "window.h"
#include "lever.h"

int main( int argc , char* argv[] ){
    window win;
    win.init();
    Lever lever( win );

    std::srand(std::time(nullptr));
    while( !lever.endgame ){
        lever.event();
        lever.logic();
        lever.render();
        lever.deleteBlock();
        lever.gameSpeed();

        SDL_Delay( lever.delay );
    }
    lever.quit();
    win.quit();
    return 0;
}
