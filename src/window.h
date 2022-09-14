#pragma once

#include "../includes/SDL.h"
#include "../includes/SDL_image.h"
#include <iostream>

#include "properties.h"

class window{
public:
                        window();
                        ~window();

    windowProperty      wP;

    static SDL_Renderer *rend;
    void                init();
    void                handleWindowEvent(boardPorperties &bP, tools &tools);
    void                render();
    void                update();
private: 

    SDL_Window          *wind;
    SDL_Event           event;
    bool                first = true;
    int                 oX, oY,                     //original X/Y position (of cursor)
                            yF, xF;                 //Y/X final position (of cursor)
    void                updateWP(boardPorperties bP);

};
