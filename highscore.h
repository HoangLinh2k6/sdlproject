#ifndef HIGHSCORE_H
#define HIGHSOCRE_H

#include "background.h"
#include "button.h"
#include "score.h"
#include "window.h"
#include "game.h"

struct HighScore{
    window win;
    Background background;
    Button deleteHighScoreButton;
    Button quitButton;
    Score highScore;
    Game game;

    HighScore( window _win);

    void render();
    void event();
    void quit();

};


#endif // HIGHSCORE_H
