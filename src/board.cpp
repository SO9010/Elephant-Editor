#include "board.h"
board::board(){

}

board::~board(){

}

void board::drawGhostCursor(windowProperty wP){
        SDL_Rect            ghostCursor = {0, 0, bP.cellSize,
                                             bP.cellSize}; 
        ghostCursor.x = ((wP.cursorX / bP.cellSize) * bP.cellSize);
        ghostCursor.y = ((wP.cursorY / bP.cellSize) * bP.cellSize);
        SDL_SetRenderDrawColor(window::rend, 33, 33, 33, 255);
        SDL_RenderFillRect(window::rend, &ghostCursor);
}

void board::createCanvas(){
    bP.drawArea.clear();
    bP.drawArea.resize(bP.board.x-2, std::vector<SDL_Color *>(bP.board.y-2, NULL));
}

void board::resizeCanvas(){
    this->createCanvas();
}

void board::renderCanvas(){
    SDL_Rect rect {0, 0, bP.cellSize, bP.cellSize};
    for(int i = 0; i < bP.drawArea.size(); i++){
        for(int j = 0; j < bP.drawArea[i].size(); j++){
            SDL_SetRenderDrawColor(window::rend, bP.drawArea[i][j]->r, bP.drawArea[i][j]->g, bP.drawArea[i][j]->b, bP.drawArea[i][j]->a);
           // SDL_RenderFillRect(window::rend, );
           for(int i = 0, j = 0; i < 1+(bP.board.x + 2)*bP.cellSize || j < 1+(bP.board.y + 2)*bP.cellSize; i+=bP.cellSize, j+=bP.cellSize){
                SDL_RenderFillRect(window::rend, &rect);
           }
        }
    }
}

void board::drawGrid(windowProperty wP){
    bP.gridX = (wP.cW - ((bP.board.x + 2)*bP.cellSize)/2);
    bP.gridY = (wP.cH - ((bP.board.y + 2)*bP.cellSize)/2);
    for(int i = 0, j = 0; i < 1+(bP.board.x + 2)*bP.cellSize || j < 1+(bP.board.y + 2)*bP.cellSize; i+=bP.cellSize, j+=bP.cellSize){
        SDL_SetRenderDrawColor(window::rend, 40, 40, 40, 255);
        //Draw grid
        //Verticle Lines
        SDL_RenderDrawLineF(window::rend, i+bP.gridX, 0, i+bP.gridX, wP.h); 
        //Horizontal Lines
        SDL_RenderDrawLineF(window::rend, 0, j+bP.gridY, wP.w, j+bP.gridY);
        //Draw White Outiline 
        //Verticle Lines
        if(i == bP.cellSize*2 || i == ((bP.board.x + 2)*bP.cellSize)-(bP.cellSize*2)){
            SDL_SetRenderDrawColor(window::rend, 100, 100, 100, 255); 
            SDL_RenderDrawLineF(window::rend, i+bP.gridX, 0, i+bP.gridX, wP.h);
            bP.board.windowX = i+bP.gridX;
        }
        //Horizontal Lines
        if(j == bP.cellSize*2 || j == ((bP.board.y + 2)*bP.cellSize)-(bP.cellSize*2)){ 
            SDL_SetRenderDrawColor(window::rend, 100, 100, 100, 255); 
            SDL_RenderDrawLineF(window::rend, 0, j+bP.gridY, wP.w, j+bP.gridY);
            bP.board.windowY = j+bP.gridY;
        }
    }
}