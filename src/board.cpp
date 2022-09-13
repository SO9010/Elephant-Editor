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

void board::resizeCanvas(int &originalBoardX, int &originalBoardY){
    if(originalBoardX != bP.board.x -2 || originalBoardY != bP.board.y -2){
        std::vector<std::vector<SDL_Color *>> tmpCanvas {bP.drawArea};
        SDL_Color tmp = {255, 255, 255 , 0};
        bP.drawArea.clear();
        bP.drawArea.resize(bP.board.x-2, std::vector<SDL_Color *>(bP.board.y-2, &tmp));
        for(int i = 0; i < bP.drawArea.size() && i < tmpCanvas.size(); i++){
            for(int j = 0; j < bP.drawArea[i].size() && j < tmpCanvas[i].size(); j++){
                if(tmpCanvas[i][j] != nullptr){
                    std::cout << i << " | " << j << "\n";
                    if(originalBoardX < bP.board.x -2 || originalBoardY < bP.board.y -2){
                        bP.drawArea[i+1][j+1] = tmpCanvas[i][j];    
                    }
                    else{
                        //TODO fix bug where right and bottom get cut off to early
                        if(i-1>=0 && j-1>=0){
                            bP.drawArea[i-1][j-1] = tmpCanvas[i][j];    
                        }
                    }
                }
            }
        }
        std::cout << std::endl;
        tmpCanvas.clear();
        originalBoardX = bP.board.x -2;
        originalBoardY = bP.board.y -2;        
    }
}

void board::renderCanvas(){
    SDL_Rect pixel {0, 0, bP.cellSize, bP.cellSize};
    int cellsizeTotalX = 0;
    int cellsizeTotalY = 0;
    for(int i = 0; i < bP.drawArea.size(); i++){
        pixel.y = bP.gridY+(bP.cellSize*2) + cellsizeTotalY;
        for(int j = 0; j < bP.drawArea[i].size(); j++){
            if(bP.drawArea[i][j] != NULL){
            SDL_SetRenderDrawColor(window::rend, bP.drawArea[i][j]->r, bP.drawArea[i][j]->g, bP.drawArea[i][j]->b, bP.drawArea[i][j]->a);
            pixel.x = (bP.gridX+(bP.cellSize*2))+cellsizeTotalX;
            SDL_RenderFillRect(window::rend, &pixel);
            cellsizeTotalX += bP.cellSize;
            }
        }
        pixel.y += bP.cellSize;
        cellsizeTotalY += bP.cellSize;
        pixel.x = 0;
        cellsizeTotalX = 0;
    }
}

void board::drawGrid(windowProperty wP){
    bP.gridX = (wP.cW - ((bP.board.x + 2)*bP.cellSize)/2);
    bP.gridY = (wP.cH - ((bP.board.y + 2)*bP.cellSize)/2);
    for(int i = 0, j = 0; i < 1+(bP.board.x + 2)*bP.cellSize || j < 1+(bP.board.y + 2)*bP.cellSize; i+=bP.cellSize, j+=bP.cellSize){
        SDL_SetRenderDrawColor(window::rend, 255, 255, 255, 20);
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
    this->renderCanvas();
}