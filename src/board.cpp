#include "board.h"


board::board(){

}

board::~board(){

}

void board::drawGhostCursor(int cursorX, int cursorY){
        ghostCursor.x = (cursorX / bP.cellSize) * bP.cellSize;
        ghostCursor.y = (cursorY / bP.cellSize) * bP.cellSize;
        SDL_SetRenderDrawColor(window::rend, 144, 144, 144, 255);
        SDL_RenderFillRect(window::rend, &ghostCursor);
}

void board::createCanvas(){
    canvas.resize(bP.board.x, std::vector<int>(bP.board.y, -1));
    
}
int tmpX = 0, tmpY = 0;
void board::drawGrid(windowProperty wP){

    tmpX += bP.displaceY, tmpY += bP.dispalceX;

    centerWindowWidth = ((wP.w/2) - (((bP.board.x + 2)*bP.cellSize)/2)) + bP.dispalceX;
    centerWindowHight = ((wP.h/2) - (((bP.board.y + 2)*bP.cellSize)/2)) + bP.displaceY;
    for(int i = 0, j = 0; i < 1+(bP.board.x + 2)*bP.cellSize || j < 1+(bP.board.y + 2)*bP.cellSize; i+=bP.cellSize, j+=bP.cellSize){
        SDL_SetRenderDrawColor(window::rend, 40, 40, 40, 255);
        //Draw grid
        //Verticle Lines
        SDL_RenderDrawLineF(window::rend, i+centerWindowWidth, 0, i+centerWindowWidth, wP.h); 
        //Horizontal Lines
        SDL_RenderDrawLineF(window::rend, 0, j+centerWindowHight, wP.w, j+centerWindowHight);
        //Draw White Outiline 
        //Verticle Lines
        if(i == bP.cellSize*2 || i == ((bP.board.x + 2)*bP.cellSize)-(bP.cellSize*2)){
            SDL_SetRenderDrawColor(window::rend, 100, 100, 100, 255); 
            SDL_RenderDrawLineF(window::rend, i+centerWindowWidth, 0, i+centerWindowWidth, wP.h);
            bP.board.windowX = i+centerWindowWidth;
        }
        //Horizontal Lines
        if(j == bP.cellSize*2 || j == ((bP.board.y + 2)*bP.cellSize)-(bP.cellSize*2)){ 
            SDL_SetRenderDrawColor(window::rend, 100, 100, 100, 255); 
            SDL_RenderDrawLineF(window::rend, 0, j+centerWindowHight, wP.w, j+centerWindowHight);
            bP.board.windowY = j+centerWindowHight;
        }
        drawGhostCursor(wP.cursorX, wP.cursorY);
    }
}