#include "texture.h"
#include "background.h"

Background::Background( SDL_Renderer *renderer, const char *filename ) {
    texture.setRenderer(renderer);
    texture.loadTexture(filename);
}

void Background::scroll(int distance) {
    scrollingOffset -= distance;
    if( scrollingOffset < 0 ) { scrollingOffset = texture.w; }
}

void Background::render() {
    texture.render( scrollingOffset, 0);
    texture.render( scrollingOffset - texture.w, 0);
}
void Background::quit() {
    texture.free();
}
