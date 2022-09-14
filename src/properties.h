#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string.h>

struct tools{
    SDL_Color           clickColour = {45, 200, 100, 255};
};

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
    int                 cWo, cHo;               //Center width/hight + offset
    int                 cW, cH;               //Center width/hight
    bool                running = false;
    int                 cursorX, cursorY;       //Cursor position x/y
};