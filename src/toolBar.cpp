#include "toolBar.h"
#include "board.h"

SDL_Color toolBar::primaryColour = {255, 255, 255, 255};

toolBar::toolBar(){
    tools.clickColour = primaryColour;
    tools.toolBarHeight = 292;
}

toolBar::~toolBar(){
    
}

void toolBar::changeCursor(std::string cursor, int offSet){
    SDL_Surface *surface;
    std::string cursorLocation = "../assets/tools/" + cursor + ".png";
    surface = IMG_Load(cursorLocation.c_str());
    tools.cursor = SDL_CreateColorCursor(surface, offSet, offSet);
    SDL_SetCursor(tools.cursor);
    SDL_FreeSurface(surface);
}
void toolBar::changeCursor(std::string cursor){
    SDL_Surface *surface;
    std::string cursorLocation = "../assets/tools/" + cursor + ".png";
    surface = IMG_Load(cursorLocation.c_str());
    tools.cursor = SDL_CreateColorCursor(surface, 0, 0);
    SDL_SetCursor(tools.cursor);
    SDL_FreeSurface(surface);
}
void toolBar::changeCursor(std::string cursor, int offSetX, int offSetY){
    SDL_Surface *surface;
    std::string cursorLocation = "../assets/tools/" + cursor + ".png";
    surface = IMG_Load(cursorLocation.c_str());
    tools.cursor = SDL_CreateColorCursor(surface, offSetX, offSetY);
    SDL_SetCursor(tools.cursor);
    SDL_FreeSurface(surface);
}

void toolBar::moveTool(){
    tools.cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEALL);
    SDL_SetCursor(tools.cursor);
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
    if(tools.zoomIn){
        this->zoomIn();
    }
    else if(tools.zoomOut){
        this->zoomOut();
    }
    else if(tools.moveTool){
        this->moveTool();
    }
    else if(tools.squareTool){
        this->squareTool();
    }
    else if(tools.triangelTool){
        this->triangelTool();
    }
    else if(tools.circleTool){
        this->circleTool();
    }
    else if(tools.penTool){
        this->penTool();
    }
    else if(tools.eraserTool){
        this->eraserTool();
    }
}
void toolBar::renderToolBar(windowProperty wP, boardPorperties bP){
    SDL_Rect dockInner = {4, wP.cH-(tools.toolBarHeight/2)+4, 42, tools.toolBarHeight-8};
    SDL_Rect dockOuter = {0, wP.cH-(tools.toolBarHeight/2), 50, tools.toolBarHeight};

    SDL_Rect toolBackDrop = {8, wP.cH-(tools.toolBarHeight/2)-31, 33, 33};
    SDL_Rect tool = {9, wP.cH-(tools.toolBarHeight/2)-30, 30, 30};
    SDL_Texture *tex;

    SDL_SetRenderDrawColor(window::rend, 36 ,36, 36, 225);
    SDL_RenderFillRect(window::rend, &dockOuter);

    SDL_SetRenderDrawColor(window::rend, 48, 48, 48, 225);
    SDL_RenderFillRect(window::rend, &dockInner);

    std::string icon[7] = {"move.ico", "zoomIn.ico", "square.ico", "triangle.ico", "circle.ico", "pencil.ico", "eraser.ico"};
    /*    Draw tool icons    */
    for(int i = 0; i < 7 ; i++){
        SDL_SetRenderDrawColor(window::rend, 60, 60, 60, 225);
        toolBackDrop.y += 40;
        tool.y += 40;
        std::string ico = "../assets/tools/" + icon[i] + ".png";
        tex = IMG_LoadTexture(window::rend, ico.c_str());
        SDL_RenderFillRect(window::rend, &toolBackDrop);
        SDL_RenderCopy(window::rend, tex, NULL, &tool);
    }
}