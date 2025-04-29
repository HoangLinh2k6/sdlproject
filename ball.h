#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include <SDL_image.h>

#include "texture.h"
#include "energy.h"

struct Ball{
    Texture texture;
    int x = 100, y = 300, y0 = 300, w, h, y1 = 0, angle = 0, lane = 0, RotationAngle = 0 ;
    bool jump = false;

    Ball( SDL_Renderer *renderer, const char *filename );


    void up();
    void down();
    void Jump();
    void doJump();
    void roll();

    void render();
    void quit();
};

#endif // BALL_H
