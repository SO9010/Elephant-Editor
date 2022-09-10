#include "window.h"
#include "board.h"

window *wind = NULL;

int main(){
    wind = new window();
    wind->init();
    board grid;

    grid.bP.boardX = 8;
    grid.bP.boardY = 8;
    grid.bP.cellSize = 64;


    while(wind->windowProperties().running){
        wind->handleWindowEvent(grid.bP.boardX, grid.bP.boardY, grid.bP.cellSize, grid.bP.dispalceX, grid.bP.displaceY); 
        
        grid.drawGrid(wind->windowProperties().w, wind->windowProperties().h, grid.bP.dispalceX, grid.bP.displaceY);
        
        wind->update();
        wind->render();
    }
    return 0;
}
