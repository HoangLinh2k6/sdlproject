#ifndef LEVER_H
#define LEVER_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


#include "defs.h"
#include "window.h"
#include "background.h"
#include "texture.h"
#include "ball.h"
#include "block.h"

struct Lever{
    window win;
    Background background;
    Ball ball;
    std::vector<Block> block;
    int  a = 100, x = 100, scroll = 50, abc = 10, blockSize;
    bool endgame = false;
    Lever( window& _win);

    void event();
    void logic();
    void render();
    void deleteBlock();

    void quit();
};

#endif // LEVER_H
