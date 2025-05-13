#ifndef LOST_H
#define LOST_H

#include <SDL.h>

#include "background.h"
#include "window.h"
#include "game.h"
#include "button.h"
#include "score.h"

struct Lost{
    window win;
    Background background;
    Score highScore;
    Button menuButton;
    Button exitButton;
    Lost( window _win );
    Game game = Game::Lost;

    void setScore( int score );
    void render();
    void event();
    void quit();
};

#endif // LOST_H
