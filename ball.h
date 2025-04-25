#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include <SDL_image.h>
#include <cmath>

#include "texture.h"
#include "exception.h"



struct Ball{
    Texture texture;
    int x = 100, y = 300, w, h, y1 = 0, a = 0, lane = 0, RotationAngle = 0 ;
    bool jump = false;

    Ball( SDL_Renderer *renderer, const char *filename ){
        texture.setRenderer(renderer);
        texture.loadTexture(filename);
        w = texture.get_w();
        h = texture.get_h();
    }
    void up(){
        if( !jump && lane != -1 ){
            lane --;
        }
    }
    void down(){
        if( !jump && lane != 1){
            lane ++;
        }
    }
    void Jump(){
        jump = true;
    }
    void doJump(){
        if(jump){
            a += 30;
            y1 = 200 * sin( a / 180.0 * M_PI );
            if( a == 180 ){
                a = 0;
                jump = false;
            }
        }
    }
    void render(){
        texture.render( x, (y - y1 + 100 * lane), RotationAngle);
        roll();
    }
    void roll(){
        if( RotationAngle < 360 ) RotationAngle +=60;
        else RotationAngle = 60;
    }
    void quit(){
        texture.free();
    }
};

#endif // BALL_H
