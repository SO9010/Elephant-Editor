#include "board.h"
board::board(){

}

board::~board(){

}

void board::drawGhostCursor(windowProperty wP){
        ghostCursor.x = (wP.cursorX / bP.cellSize) * bP.cellSize;
        ghostCursor.y = (wP.cursorY / bP.cellSize) * bP.cellSize;
        SDL_SetRenderDrawColor(window::rend, 144, 144, 144, 255);
        SDL_RenderFillRect(window::rend, &ghostCursor);
}

void board::createCanvas(){
    bP.drawArea.clear();
    bP.drawArea.resize(bP.board.x-2, std::vector<std::string>(bP.board.y-2, "-1"));
}

void board::resizeCanvas(){
    this->createCanvas();
}

void board::renderCanvas(){
    for(int i = 0; i <= bP.drawArea.size(); i++){
        for(int j = 0; i <= bP.drawArea[i].size(); j++){
            if(std::stoi(bP.drawArea[i][j]) >= 0){
                for(int i = 0; i < bP.drawArea.size(); i++){
                    for(int j = 0; j < bP.drawArea[i].size(); j++){
                        std::cout << bP.drawArea[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                std::cout << "-----------------" << std::endl;
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