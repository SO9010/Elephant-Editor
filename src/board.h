#pragma once 

#include "window.h"

class board{
public:
    board();
    ~board();
    boardPorperties     bP;
    void                resizeCanvas();
    void                createCanvas();
    void                drawGrid(windowProperty wP);
    void                drawGhostCursor(windowProperty wP);
private:
    SDL_Rect            ghostCursor = {0, 0, bP.cellSize,
                                             bP.cellSize}; 
    void                renderCanvas();
};
