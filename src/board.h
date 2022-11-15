#pragma once 

#include "window.h"

class board{
public:
    board();
    ~board();
    boardPorperties     bP;
    void                universalResizeCanvas(int resize);
    void                resizeCanvas(int &originalBoardX, int &originalBoardY);
    void                drawGrid(windowProperty wP);
    void                drawGhostPen(windowProperty wP);
private:
    void                renderCanvas();
};
