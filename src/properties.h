#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct canvas{
    int             x, y;
    int             windowX, windowY;
    int             drawAreaX, drawAreaY;
};

struct boardPorperties{
    canvas          board;
    int             cellSize;
    int             dispalceX = 0, displaceY = 0, 
                        fDisplaceX = 0, fDisplaceY = 0;
    int             cursorX, cursorY;
};

struct windowProperty{
    int                 w, h;               //Width, hight
    bool                running;
    int                 cursorX, cursorY;   //Cursor position x/y
};