#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include "exception.h"



struct Ball{
    Texture texture;
    int x = 100, y = 300, y1 = 0, a = 0 ;

    Ball( SDL_Renderer *renderer, const char *filename ){
        texture.setRenderer(renderer);
        texture.loadTexture(filename);
    }
    void up(){
        if( a == 0)y-=100;
    }
    void down(){
        if( a == 0)y+=100;
    }
    void jump( bool &check){
        a += 20;
        y1 = 200 * sin( a / 180.0 * M_PI );
        if( a == 180 ){
            a = 0;
            check = false;
        }
    }
    void render( int roll){
        texture.render( x, (y - y1), roll);
    }
};

#endif // BALL_H
