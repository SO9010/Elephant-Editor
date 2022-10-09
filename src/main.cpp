#include "window.h"
#include "board.h"
#include "widgets/toolBar.h"
#include "widgets/colourPicker.h"

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
    colourPicker colourPicker;

    while(wind->wP.running){
        wind->handleWindowEvent(grid.bP, toolBar.toolCollection); 
        grid.resizeCanvas(originalBoardX, originalBoardY);
        grid.drawGrid(wind->wP);
        colourPicker.renderColourPicker();
        toolBar.renderToolBar(wind->wP, grid.bP);
    }
    return 0;
}
