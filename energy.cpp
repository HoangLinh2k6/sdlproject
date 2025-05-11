#include "energy.h"

Energy::Energy(SDL_Renderer* _renderer){
    renderer = _renderer;
}

void Energy::use(){
    if( energy == 100 ){ useEnergy = true; }
}

void Energy::updateEnergy(){
    if( !useEnergy && energy < 100 ){ energy ++; }
    if( useEnergy && energy > 0 ){ energy --; }
    if( useEnergy && energy == 0){ useEnergy = false; }
    filled.w = energy;
}

void Energy::render(){

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &filled);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect = { 100, 10, 100, 30 };
    SDL_RenderDrawRect(renderer, &rect);
}
