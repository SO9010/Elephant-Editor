#pragma once 

#include "window.h"

class board{
public:
    board();
    ~board();
    boardPorperties     bP;
    void                resizeCanvas(int &originalBoardX, int &originalBoardY);
    void                drawGrid(windowProperty wP);
    void                drawGhostCursor(windowProperty wP);
private:
    void                renderCanvas();
};
