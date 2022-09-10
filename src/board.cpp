#include "board.h"


board::board(){
    bP.boardX = 4;
    bP.boardY = 4;
    bP.cellSize = 16;
    bP.dispalceX = 0;
    bP.displaceY = 0;
}

board::~board(){

}

void board::createCanvas(int x, int y){
    
}

void board::drawGrid(int wW, int wH, int dsplX, int dsplY){

    float cwW, cwH;
    cwW = (wW/2) - (((bP.boardX + 2)*bP.cellSize)/2) + dsplX;
    cwH = (wH/2) - (((bP.boardY + 2)*bP.cellSize)/2) + dsplY;
    for(int i = 0, j = 0; i < 1+(bP.boardX + 2)*bP.cellSize || j < 1+(bP.boardY + 2)*bP.cellSize; i+=bP.cellSize, j+=bP.cellSize){
        SDL_SetRenderDrawColor(window::rend, 40, 40, 40, 255);
        SDL_RenderDrawLineF(window::rend, i+cwW, 0, i+cwW, wH);
        SDL_RenderDrawLineF(window::rend, 0, j+cwH, wW, j+cwH);
        // Draw White Outiline 
        if(i == bP.cellSize*2 || i == ((bP.boardX + 2)*bP.cellSize)-(bP.cellSize*2)){
            SDL_SetRenderDrawColor(window::rend, 100, 100, 100, 255); 
            SDL_RenderDrawLineF(window::rend, i+cwW, 0, i+cwW, wH);
        }
        if(j == bP.cellSize*2 || j == ((bP.boardY + 2)*bP.cellSize)-(bP.cellSize*2)){ 
            SDL_SetRenderDrawColor(window::rend, 100, 100, 100, 255); 
            SDL_RenderDrawLineF(window::rend, 0, j+cwH, wW, j+cwH);
        }
    }
}