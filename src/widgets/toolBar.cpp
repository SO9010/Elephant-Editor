#include "toolBar.h"

SDL_Color toolBar::primaryColour = {255, 255, 255, 255};

toolBar::toolBar(){
    toolCollection.clickColour = primaryColour;
    toolCollection.toolBarHeight = 292;
}

toolBar::~toolBar(){
    
}

void toolBar::changeCursor(std::string cursor, int offSet){
    SDL_Surface *surface;
    std::string cursorLocation = "../assets/toolCollection/" + cursor + ".png";
    surface = IMG_Load(cursorLocation.c_str());
    toolCollection.cursor = SDL_CreateColorCursor(surface, offSet, offSet);
    SDL_SetCursor(toolCollection.cursor);
    SDL_FreeSurface(surface);
}
void toolBar::changeCursor(std::string cursor){
    SDL_Surface *surface;
    std::string cursorLocation = "../assets/toolCollection/" + cursor + ".png";
    surface = IMG_Load(cursorLocation.c_str());
    toolCollection.cursor = SDL_CreateColorCursor(surface, 0, 0);
    SDL_SetCursor(toolCollection.cursor);
    SDL_FreeSurface(surface);
}
void toolBar::changeCursor(std::string cursor, int offSetX, int offSetY){
    SDL_Surface *surface;
    std::string cursorLocation = "../assets/toolCollection/" + cursor + ".png";
    surface = IMG_Load(cursorLocation.c_str());
    toolCollection.cursor = SDL_CreateColorCursor(surface, offSetX, offSetY);
    SDL_SetCursor(toolCollection.cursor);
    SDL_FreeSurface(surface);
}

void toolBar::moveTool(){
    toolCollection.cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEALL);
    SDL_SetCursor(toolCollection.cursor);
}

void toolBar::squareTool(){

}

void toolBar::triangelTool(){

}

void toolBar::circleTool(){

}

void toolBar::zoomIn(){
    changeCursor("zoomIn", 8);
}
void toolBar::zoomOut(){
    changeCursor("zoomOut", 8);
}
void toolBar::penTool(){
    changeCursor("pencil", 0, 31);
}

void toolBar::eraserTool(){
    changeCursor("eraser", 0, 31);
}

void toolBar::updateTools(){
    if(toolCollection.zoomIn){
        this->zoomIn();
    }
    else if(toolCollection.zoomOut){
        this->zoomOut();
    }
    else if(toolCollection.moveTool){
        this->moveTool();
    }
    else if(toolCollection.squareTool){
        this->squareTool();
    }
    else if(toolCollection.triangelTool){
        this->triangelTool();
    }
    else if(toolCollection.circleTool){
        this->circleTool();
    }
    else if(toolCollection.penTool){
        this->penTool();
    }
    else if(toolCollection.eraserTool){
        this->eraserTool();
    }
}
void toolBar::renderToolBar(windowProperty wP, boardPorperties bP){
    SDL_Rect dockInner = {4, wP.cH-(toolCollection.toolBarHeight/2)+4, 42, toolCollection.toolBarHeight-8};
    SDL_Rect dockOuter = {0, wP.cH-(toolCollection.toolBarHeight/2), 50, toolCollection.toolBarHeight};

    SDL_SetRenderDrawColor(window::rend, 36 ,36, 36, 225);
    SDL_RenderFillRect(window::rend, &dockOuter);

    SDL_SetRenderDrawColor(window::rend, 48, 48, 48, 225);
    SDL_RenderFillRect(window::rend, &dockInner);

    std::string icon[7] = {"move.ico", "zoomIn.ico", "square.ico", "triangle.ico", "circle.ico", "pencil.ico", "eraser.ico"};
    /*    Draw tool icons    */
    for(int i = 0; i < 7 ; i++){
        SDL_SetRenderDrawColor(window::rend, 60, 60, 60, 225);
        std::string ico = "../assets/toolCollection/" + icon[i] + ".png";
        button tool;
        tool.buttonHeight = tool.buttonWidth = 34;
        //tool.buttonImage = ico;
        tool.buttonY = wP.cH-(toolCollection.toolBarHeight/2) + 9 + i * 40;
        tool.buttonX = 8;
        tool.showButton();
    }
}