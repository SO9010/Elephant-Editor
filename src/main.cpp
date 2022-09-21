#include "window.h"
#include "board.h"

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


    while(wind->wP.running){
        wind->handleWindowEvent(grid.bP); 
    }
    return 0;
}
