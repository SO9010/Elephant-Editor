#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string.h>

struct canvas{
    int                 x, y;
    int                 windowX, windowY;
};

struct boardPorperties{
    canvas              board;
    std::vector<std::vector<SDL_Color *>> drawArea;    
    int                 cellSize;
    int                 displaceX = 0, displaceY = 0, 
                            fDisplaceX = 0, fDisplaceY = 0;
    int                 gridX, gridY;
};

struct windowProperty{
    int                 w, h;                   //Width, hight
    int                 cW, cH;                 //Center width/hight + offset
    bool                running = false;
    int                 cursorX, cursorY;       //Cursor position x/y
};