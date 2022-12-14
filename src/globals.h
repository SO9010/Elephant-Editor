#pragma once 

#include "/usr/include/SDL2/SDL.h"
#include "/usr/include/SDL2/SDL_image.h"
#include "/usr/include/SDL2/SDL_ttf.h"
#include <vector>
#include <string>
#include <memory>

struct tools{
    int                 toolBarHeight;
    SDL_Cursor*         cursor;
    SDL_Color           clickColour;
    SDL_Color           secondaryColour;
    Uint8               penSize = 1;

    bool                zoomIn = false;
    bool                zoomOut = false;
    bool                moveTool = false;
    bool                squareTool = false;
    bool                triangelTool = false;
    bool                circleTool = false;
    bool                penTool = true;
    bool                eraserTool = false;
};

struct canvas{
    int                 x, y;
    int                 windowX, windowY;
};

struct boardPorperties{
    canvas              board;
    std::vector<std::vector<SDL_Color>> drawArea;    
    int                 cellSize;
    int                 displaceX = 0, displaceY = 0, 
                            fDisplaceX = 0, fDisplaceY = 0;
    int                 gridX, gridY;
};

struct windowProperty{
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    bool                leftClick = false;
    int                 w, h;                   //Width, hight
    int                 cWo, cHo;               //Center width/hight + offset
    int                 cW, cH;                 //Center width/hight
    bool                running = false;
    int                 cursorX, cursorY;       //Cursor position x/y
};
