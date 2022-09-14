#include "window.h"
#include "board.h"
#include "toolBar.h"

window *wind = NULL;

int main(){
    wind = new window();
    wind->init();

    board grid;
    int originalBoardX = 4;
    int originalBoardY = 4;
    grid.bP.board.x = 8;
    grid.bP.board.y = 8;
    grid.bP.cellSize = 64;

    toolBar toolBar;

    while(wind->wP.running){
        wind->handleWindowEvent(grid.bP, toolBar.tools); 
        grid.resizeCanvas(originalBoardX, originalBoardY);
        grid.drawGrid(wind->wP);
        toolBar.renderToolBar(wind->wP);
    }
    return 0;
}
