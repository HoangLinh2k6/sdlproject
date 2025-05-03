#ifndef MENU_H
#define MENU_H

#include <SDL.h>

#include "background.h"
#include "window.h"
#include "game.h"
#include "button.h"

struct Menu{
    Menu( window& _win );
    window win;
    Background background;
    Button playButton;
    Button highScoreButton;
    Button exitButton;
    Game game = Game::Menu;

    void render();
    void event();
    void quit();
};

#endif // MENU_H
