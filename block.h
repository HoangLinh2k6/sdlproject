#ifndef BLOCK_H
#define BLOCK_H

#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "texture.h"
#include "ball.h"

struct Block{
    Texture texture;
    int x = 800, y = 300, y0 = 300 , w, h, lane ;

    Block( SDL_Renderer *renderer, const char *filename, int _lane );

    void scroll(int distance);
    bool checkCollision( Ball ball);

    void render();
    void quit();
};
Block createBlock(SDL_Renderer *renderer, const char *filename, int lane);

#endif // BLOCK_H
