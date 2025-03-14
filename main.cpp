#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "background.h"
#include "texture.h"
#include "window.h"

int main( int argc , char* argv[] ){
    window win;
    win.init();
    win.quit();
    return 0;
}
