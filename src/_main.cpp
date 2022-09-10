#include "window.h"
#include "board.h"

window *wind = NULL;

int main(){
    wind = new window();
    wind->init();

    int boardX, boardY, cellSize, dispalceX, displaceY;
    
    boardX = 8;
    boardY = 8;
    cellSize = 64;

    bool mouseHover = false;
    bool mouseActive = false;

    while(wind->windowProperties().running){
        wind->handleWindowEvent(boardX, boardY, cellSize, dispalceX, displaceY); 
        
        drawGrid(boardX, boardY, cellSize, wind->windowProperties().w, wind->windowProperties().h, dispalceX, displaceY);
        
        wind->update();
        wind->render();
    }
    return 0;
}
