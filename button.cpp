#include <string>

#include "button.h"
#include "defs.h"

Button::Button( SDL_Renderer *renderer, int _x, int _y, const char* text, int _size ):
    texture{ renderer, BUTTON_IMAGE },
    font{ renderer, text, _size },
    x{ _x },
    y{ _y },
    w{ texture.get_w() },
    h{ texture.get_h() }
{}

void Button::render(){
    texture.render( x, y );
    font.render( x + 20 , y );
}

bool Button::click( int _x, int _y ){
    return ( _x > x && _x < ( x + w )
            && _y > y && _y < ( y + h) );
}

void Button::quit(){
    texture.free();
    font.free();
}
