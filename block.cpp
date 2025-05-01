#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "block.h"
#include "texture.h"
#include "ball.h"


Block::Block( SDL_Renderer *renderer, const char *filename, int _lane ):
    texture{ renderer, filename },
    w{ texture.get_w() },
    h{ texture.get_h() },
    lane{ _lane }
{
}
void Block::scroll(int distance) {
    x -= distance;
}
void Block::render(){
    y = y0 + 100 * lane;
    texture.render( x, y );
}
bool Block::checkCollision( Ball ball){
    return ( !ball.jump &&
           ( ball.x + ball.w <= x + w )&&
           ( ball.x + ball.w >= x )&&
           ( ball.y + ball.h <= y + h )&&
           ( ball.y + ball.h >= y));
}
void Block::quit(){
    texture.free();
}

Block createBlock(SDL_Renderer *renderer, const char *filename, int lane){
    Block block( renderer, filename, lane );
    return block;
}
