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
    Energy energy;
    std::vector<Block> block;
    int  delay = 100, scroll = 50, time = 7, blockSize;
    bool endgame = false;

    Lever( window& _win);

    void event();
    void logic();
    void render();
    void deleteBlock();
    void gameSpeed();

    void quit();
};

#endif // LEVER_H
