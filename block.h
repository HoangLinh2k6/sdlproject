#ifndef BLOCK_H
#define BLOCK_H

#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "texture.h"
#include "ball.h"
#include "exception.h"

struct Block{
    Texture texture;
    int x = 800, y = 300 , w, h, lane ;

    Block( SDL_Renderer *renderer, const char *filename, int _lane ){
        texture.setRenderer(renderer);
        texture.loadTexture(filename);
        lane = _lane;
        w = texture.get_w();
        h = texture.get_h();
    }
    void scroll(int distance) {
        x -= distance;
    }
    void render(){
        texture.render( x, y + 100 * lane);
    }
    bool checkCollision( Ball ball){
        return ( ball.lane == lane &&
                ball.x < x + w &&
                ball.x + ball.w > x &&
                ball.y < y + h &&
                ball.y + ball.h > y);
    }
    void quit(){
        texture.free();
    }
};
Block createBlock(SDL_Renderer *renderer, const char *filename){
    int lane = std::rand() % 3 - 1;
    Block block( renderer, filename, lane );
    return block;
}

#endif // BLOCK_H
