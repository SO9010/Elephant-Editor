#pragma once


#include <iostream>

#include "globals.h"

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
    int                 oX, oY,                     //original X/Y position (of cursor)
                            yF, xF;                 //Y/X final position (of cursor)
    void drawGhostCursor(boardPorperties bP);
    int                 bmp[2] = {0,0};
    void                updateWP(boardPorperties bP);
    bool                first = true;
    bool                inDrawArea(int x, int y, boardPorperties bP);
    bool                inToolBar(int x, int y, boardPorperties bP, tools tools);
};
