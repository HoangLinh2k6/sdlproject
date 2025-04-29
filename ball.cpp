#include <cmath>
#include <iostream>

#include "ball.h"
#include "texture.h"

Ball::Ball( SDL_Renderer *renderer, const char *filename ){
    texture.setRenderer(renderer);
    texture.loadTexture(filename);
    w = texture.get_w();
    h = texture.get_h();
}

void Ball::up(){
    if( !jump && lane != -1 ){
        lane --;
    }
}

void Ball::down(){
    if( !jump && lane != 1){
        lane ++;
    }
}

void Ball::Jump(){
    jump = true;
}

void Ball::doJump(){
    if(jump){
        angle += 30;
        y1 = 200 * sin( angle / 180.0 * M_PI );
        if( angle == 180 ){
            angle = 0;
            jump = false;
        }
    }
}

void Ball::roll(){
    if( RotationAngle < 360 ) RotationAngle +=60;
    else RotationAngle = 60;
}


void Ball::render(){
    y = y0 - y1 + 100 * lane;
    texture.render( x, y, RotationAngle);
    roll();
}

void Ball::quit(){
    texture.free();
}


