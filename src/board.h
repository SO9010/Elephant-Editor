#pragma once 

#include "window.h"
#include <vector>

struct boardPorperties{
    int boardX, boardY, 
        cellSize, dispalceX, 
        displaceY;
};

class board{
private:

public:
    board();
    ~board();

    boardPorperties bP;

    void createCanvas(int x, int y);
    void drawGrid(int wW, int wH, int dsplX, int dsplY);
};
