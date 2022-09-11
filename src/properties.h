#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string.h>

struct canvas{
    int                 x, y;
    int                 windowX, windowY;
    int                 drawAreaX, drawAreaY;
};

struct boardPorperties{
    canvas              board;
    std::vector<std::vector<std::string>> drawArea;     /*The format for the number will be:
                                                        *   |-----|-----|-----|-----|---------------|
                                                        *   | [R] | [G] | [B] | [A] | [Render/Hint] |
                                                        *   |-----|-----|-----|-----|---------------|
                                                        *   | 000 | 000 | 000 | 000 |       0       |
                                                        */
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