#ifndef ENERGY_H
#define ENERGY_H

#include <iostream>
#include <SDL.h>

#include "window.h"

struct Energy{
    int energy = 100;
    bool useEnergy = false;
    SDL_Renderer *renderer;

    SDL_Rect filled = {100,10,0,30};

    Energy( SDL_Renderer* _renderer );

    void use();
    void updateEnergy();
    void render();

};

#endif // ENERGY_H
