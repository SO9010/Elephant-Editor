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
    std::string cursorLocation = "../assets/cursor/" + cursor + ".png";
    surface = IMG_Load(cursorLocation.c_str());
    toolCollection.cursor = SDL_CreateColorCursor(surface, offSet, offSet);
    SDL_SetCursor(toolCollection.cursor);
    SDL_FreeSurface(surface);
}
void toolBar::changeCursor(std::string cursor){
    SDL_Surface *surface;
    std::string cursorLocation = "../assets/cursor/" + cursor + ".png";
    surface = IMG_Load(cursorLocation.c_str());
    toolCollection.cursor = SDL_CreateColorCursor(surface, 0, 0);
    SDL_SetCursor(toolCollection.cursor);
    SDL_FreeSurface(surface);
}
void toolBar::changeCursor(std::string cursor, int offSetX, int offSetY){
    SDL_Surface *surface;
    std::string cursorLocation = "../assets/cursor/" + cursor + ".png";
    surface = IMG_Load(cursorLocation.c_str());
    toolCollection.cursor = SDL_CreateColorCursor(surface, offSetX, offSetY);
    SDL_SetCursor(toolCollection.cursor);
    SDL_FreeSurface(surface);
}

void changeClicked(tools &toolCollection){
        toolCollection.zoomIn = false;
        toolCollection.zoomOut = false;
        toolCollection.squareTool = false;
        toolCollection.triangelTool = false;
        toolCollection.circleTool = false;
        toolCollection.penTool = false;
        toolCollection.eraserTool = false;
        toolCollection.moveTool = false;
}

void toolBar::renderToolBar(windowProperty wP, boardPorperties bP){
    SDL_Rect dockInner = {4, wP.cH-(toolCollection.toolBarHeight/2)+4, 42, toolCollection.toolBarHeight-8};
    SDL_Rect dockOuter = {0, wP.cH-(toolCollection.toolBarHeight/2), 50, toolCollection.toolBarHeight};

    SDL_SetRenderDrawColor(window::rend, 36 ,36, 36, 225);
    SDL_RenderFillRect(window::rend, &dockOuter);

    SDL_SetRenderDrawColor(window::rend, 48, 48, 48, 225);
    SDL_RenderFillRect(window::rend, &dockInner);



    button moveButton;
    moveButton.buttonHeight = 34;
    moveButton.buttonWidth = 34;
    moveButton.buttonY = wP.cH-(toolCollection.toolBarHeight/2) + 9;
    moveButton.buttonX = 7;
    moveButton.buttonImage = "../assets/tools/move.ico.png";
    if(moveButton.clicked(wP)){
        changeClicked(toolCollection);
        toolCollection.moveTool = true;
    }
    if(toolCollection.moveTool){
        moveButton.active = true;
        toolCollection.cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEALL);
        SDL_SetCursor(toolCollection.cursor);
    }
    else{
        moveButton.active = false;
    }
    moveButton.showButton();

    button zoomButton;
    zoomButton.buttonHeight = 34;
    zoomButton.buttonWidth = 34;
    zoomButton.buttonY = wP.cH-(toolCollection.toolBarHeight/2) + 49;
    zoomButton.buttonX = 7;
    zoomButton.buttonImage = "../assets/tools/zoomIn.ico.png";
    if(zoomButton.clicked(wP)){
        changeClicked(toolCollection);
        toolCollection.zoomIn = true;
    }
    if(toolCollection.zoomIn){
        zoomButton.active = true;
        changeCursor("zoomIn", 8);
    }
    else if(toolCollection.zoomOut){
        zoomButton.active = true;
        changeCursor("zoomOut", 8);
    }
    else{
        zoomButton.active = false;
    }
    zoomButton.showButton();
    
    button squareButton;
    squareButton.buttonHeight = 34;
    squareButton.buttonWidth = 34;
    squareButton.buttonY = wP.cH-(toolCollection.toolBarHeight/2) + 89;
    squareButton.buttonX = 7;
    squareButton.buttonImage = "../assets/tools/square.ico.png";
    if(squareButton.clicked(wP)){
        changeClicked(toolCollection);
        toolCollection.squareTool = true;
    }
    if(toolCollection.squareTool){
        squareButton.active = true;
        changeCursor("square", 8);
    }
    else{
        squareButton.active = false;
    }
    squareButton.showButton();
    button triangleButton;
    triangleButton.buttonHeight = 34;
    triangleButton.buttonWidth = 34;
    triangleButton.buttonY = wP.cH-(toolCollection.toolBarHeight/2) + 129;
    triangleButton.buttonX = 7;
    triangleButton.buttonImage = "../assets/tools/triangle.ico.png";
    if(triangleButton.clicked(wP)){
        changeClicked(toolCollection);
        toolCollection.triangelTool = true;
    }
    if(toolCollection.triangelTool){
        triangleButton.active = true;
        changeCursor("triangle", 8);
    }
    else{
        triangleButton.active = false;
    }
    triangleButton.showButton();
    button circleButton;
    circleButton.buttonHeight = 34;
    circleButton.buttonWidth = 34;
    circleButton.buttonY = wP.cH-(toolCollection.toolBarHeight/2) + 169;
    circleButton.buttonX = 7;
    circleButton.buttonImage = "../assets/tools/circle.ico.png";
    if(circleButton.clicked(wP)){
        changeClicked(toolCollection);
        toolCollection.circleTool = true;
    }
    if(toolCollection.circleTool){
        circleButton.active = true;
        changeCursor("eclipse", 8);
    }
    else{
        circleButton.active = false;
    }
    circleButton.showButton();

    button pencilButton;
    pencilButton.buttonHeight = 34;
    pencilButton.buttonWidth = 34;
    pencilButton.buttonY = wP.cH-(toolCollection.toolBarHeight/2) + 209;
    pencilButton.buttonX = 7;
    pencilButton.buttonImage = "../assets/tools/pencil.ico.png";
    if(pencilButton.clicked(wP)){
        changeClicked(toolCollection);
        toolCollection.penTool = true;
    }
    if(toolCollection.penTool){
        pencilButton.active = true;
        changeCursor("pencil", 0, 15);
    }
    else{
        pencilButton.active = false;
    }
    pencilButton.showButton();

    button eraserButton;
    eraserButton.buttonHeight = 34;
    eraserButton.buttonWidth = 34;
    eraserButton.buttonY = wP.cH-(toolCollection.toolBarHeight/2) + 249;
    eraserButton.buttonX = 7;
    eraserButton.buttonImage = "../assets/tools/eraser.ico.png";
    if(eraserButton.clicked(wP)){
        changeClicked(toolCollection);
        toolCollection.eraserTool = true;
    }
    if(toolCollection.eraserTool){
        eraserButton.active = true;
        changeCursor("eraser", 0, 15);
    }
    else{
        eraserButton.active = false;
    }
    eraserButton.showButton();

   // handlePresses(wP, toolIconRender);
}