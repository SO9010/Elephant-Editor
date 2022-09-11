#pragma once 

#include "window.h"
#include <vector>

class board{
public:
    board();
    ~board();

    boardPorperties     bP;
    void                createCanvas();
    void                drawGrid(windowProperty wP);
private:
    std::vector<std::vector<int>> canvas;
    float               centerWindowWidth, centerWindowHight;
    SDL_Rect            ghostCursor = {0, 0, bP.cellSize,
                                             bP.cellSize};
    int displaceTotalX = 0, displaceTotalY = 0;
    
    void                drawGhostCursor(int cursorX, int cursorY);
};
