#ifndef SCORE_H
#define SCORE_H

#include <fstream>

#include "font.h"
#include "defs.h"

struct Score{
    int score = 0, highScore = 0 ;
    Font font;

    Score( SDL_Renderer* ren, const char* text, int _size );

    void checkAndCreateFile();
    void getHighScoreFromFile();
    void updateHighScore();
    void updateScore();
    void renderScore( int x, int y );
    void renderHighScore( int x, int y );
    void resetHighScore();

    const char* getScore();
    const char* getHighScore();

    void quit();

};

#endif // SCORE_H
