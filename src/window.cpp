#include "window.h"
#include "board.h"
#include "widgets/toolBar.h"
#include "ui/button.h"

SDL_Renderer* window::rend = nullptr;

window::window(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    wP.running = true; 
}

window::~window(){
    IMG_Quit();
    SDL_Quit();
    if(wP.running){
        wP.running = false;
    }
}

void window::init(){
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    wP.w = DM.w / 1.5;
    wP.h = DM.h / 1.5;
    Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_CreateWindowAndRenderer(wP.w, wP.h, flags, &wind, &rend);
    SDL_SetWindowTitle(wind, "Elephant Editor");
    SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
    SDL_SetWindowMinimumSize(wind, 320, 240);
}

void window::updateWP(boardPorperties bP){
    SDL_GetWindowSize(wind, &wP.w, &wP.h);
    wP.cWo = (wP.w/2) + bP.displaceX;
    wP.cW = (wP.w/2);
    wP.cHo = (wP.h/2) + bP.displaceY;
    wP.cH = (wP.h/2);
}

void setToolsToFalse(tools &toolCollection){
    toolCollection.zoomIn = false;
    toolCollection.zoomOut = false;
    toolCollection.moveTool = false;
    toolCollection.squareTool = false;
    toolCollection.triangelTool = false;
    toolCollection.circleTool = false;
    toolCollection.penTool = false;
    toolCollection.eraserTool = false;
}


bool window::inDrawArea(int x, int y, boardPorperties bP){
    if(x > bP.gridX+(2*bP.cellSize) && x < bP.board.windowX && 
        y > bP.gridY+(2*bP.cellSize) && y < bP.board.windowY){
        return true;
    }
    else{
        return false;
    }
}

bool window::inToolBar(int x, int y, boardPorperties bP, tools toolCollection){
    if(x < 50 && (y > wP.cH-(toolCollection.toolBarHeight/2) && y < wP.cH+(toolCollection.toolBarHeight/2))){
        return true;
    }
    else{
        return false;
    }
}
void window::handleWindowEvent(boardPorperties &bP, tools &toolCollection){
    if(SDL_WaitEvent(&event)){
        updateWP(bP);
        switch(event.type){
            case SDL_QUIT:
                wP.running = false;
            break;
            case SDL_KEYDOWN:
                if(wP.state[SDL_SCANCODE_EQUALS]){
                    if(bP.board.x <= 128){
                        bP.board.x += 2;
                    }
                    if(bP.board.y <= 128){
                        bP.board.y += 2;
                    }
                }
                else if(wP.state[SDL_SCANCODE_MINUS]){
                    if(bP.board.x > 4){
                        bP.board.x -= 2;
                    }
                    if(bP.board.y > 4){
                        bP.board.y -= 2;
                    }
                }
                else if(wP.state[SDL_SCANCODE_F]){
                    if(toolCollection.zoomIn){
                        setToolsToFalse(toolCollection);
                        toolCollection.zoomOut = true;
                    }
                    else if(!toolCollection.zoomIn){
                        setToolsToFalse(toolCollection);
                        toolCollection.zoomIn = true;
                    }
                }
                else if(wP.state[SDL_SCANCODE_M]){
                    setToolsToFalse(toolCollection);
                    toolCollection.moveTool = true;
                }
                else if(wP.state[SDL_SCANCODE_E]){
                    setToolsToFalse(toolCollection);
                    toolCollection.eraserTool = true;
                }
                else if(wP.state[SDL_SCANCODE_P]){
                    setToolsToFalse(toolCollection);
                    toolCollection.penTool = true;
                }
                else if(wP.state[SDL_SCANCODE_LCTRL] && wP.state[SDL_SCANCODE_C]){
                    SDL_Color tmp = {255,255,255,0};
                    bP.drawArea.clear();
                    bP.drawArea.resize(bP.board.x-2, std::vector<SDL_Color>(bP.board.y-2, tmp));
                }
                if(toolCollection.zoomIn || toolCollection.zoomOut){
                    if(wP.state[SDL_SCANCODE_LALT]){
                        if(toolCollection.zoomIn){
                            setToolsToFalse(toolCollection);
                            toolCollection.zoomOut = true;
                        }
                        else if(!toolCollection.zoomIn){
                            setToolsToFalse(toolCollection);
                            toolCollection.zoomIn = true;
                        }
                    }
                }
                if(toolCollection.penTool){
                    if(wP.state[SDL_SCANCODE_LCTRL] && wP.state[SDL_SCANCODE_1]){
                        toolCollection.clickColour.r = 255;
                        toolCollection.clickColour.g = 255;
                        toolCollection.clickColour.b = 255;
                        toolCollection.clickColour.a = 255;
                    }
                    if(wP.state[SDL_SCANCODE_LCTRL] && wP.state[SDL_SCANCODE_2]){
                        toolCollection.clickColour.r = 0;
                        toolCollection.clickColour.g = 0;
                        toolCollection.clickColour.b = 0;
                        toolCollection.clickColour.a = 255;                    
                    }
                    if(wP.state[SDL_SCANCODE_LCTRL] && wP.state[SDL_SCANCODE_3]){
                        toolCollection.clickColour.r = 255;
                        toolCollection.clickColour.g = 0;
                        toolCollection.clickColour.b = 0;
                        toolCollection.clickColour.a = 255;
                    }
                    if(wP.state[SDL_SCANCODE_LCTRL] && wP.state[SDL_SCANCODE_4]){
                        toolCollection.clickColour.r = 0;
                        toolCollection.clickColour.g = 255;
                        toolCollection.clickColour.b = 0;
                        toolCollection.clickColour.a = 255;
                    }
                    if(wP.state[SDL_SCANCODE_LCTRL] && wP.state[SDL_SCANCODE_5]){
                        toolCollection.clickColour.r = 255;
                        toolCollection.clickColour.g = 0;
                        toolCollection.clickColour.b = 0;
                        toolCollection.clickColour.a = 255;
                    }
                    if(wP.state[SDL_SCANCODE_LCTRL] && wP.state[SDL_SCANCODE_6]){
                        toolCollection.clickColour.r = 0;
                        toolCollection.clickColour.g = 255;
                        toolCollection.clickColour.b = 0;
                        toolCollection.clickColour.a = 255;
                    }
                }
            break;

            case SDL_MOUSEWHEEL:
                if(event.wheel.y > 0){
                    bP.cellSize += 3;
                }
                else if(event.wheel.y < 0){
                    if(bP.cellSize > 4){
                        bP.cellSize -= 3;
                    }
                }
            break;
    
            case SDL_MOUSEMOTION:  
                xF = yF = 0;
                if(SDL_GetMouseState(&wP.cursorX, &wP.cursorY) & SDL_BUTTON_MMASK){
                    int dX, dy;
                    if(first){
                        first = false;
                        oX = wP.cursorX;
                        oY = wP.cursorY;
                    }   
                    else{
                        xF = wP.cursorX;
                        yF = wP.cursorY;
                        dX = -(oX - xF);
                        dy = -(oY - yF);
                        
                        bP.displaceX = dX + bP.fDisplaceX;
                        bP.displaceY = dy + bP.fDisplaceY;
                    }
                }
                else if(SDL_GetMouseState(&wP.cursorX, &wP.cursorY) & SDL_BUTTON_LMASK){
                    wP.leftClick = true;
                    if(toolCollection.moveTool){
                        int dX, dy;
                        if(first){
                            first = false;
                            oX = wP.cursorX;
                            oY = wP.cursorY;
                        }   
                        else{
                            xF = wP.cursorX;
                            yF = wP.cursorY;
                            dX = -(oX - xF);
                            dy = -(oY - yF);
                            
                            bP.displaceX = dX + bP.fDisplaceX;
                            bP.displaceY = dy + bP.fDisplaceY;
                        }
                    }
                    if(toolCollection.penTool){
                        if(inDrawArea(wP.cursorX, wP.cursorY, bP) && !inToolBar(wP.cursorX, wP.cursorY, bP, toolCollection)){
                            int tmp[2] = {0,0};
                            for(int i = 0; i < bP.board.x - 2; i++){
                                for(int j = 0; j < bP.board.y - 2; j++){
                                    if((wP.cursorY - (bP.gridY+(3*bP.cellSize)) - 1) > (bP.cellSize * j)){
                                        tmp[1] = j + 1;
                                    } 
                                }
                                if((wP.cursorX - (bP.gridX+(3*bP.cellSize)) - 1) > (bP.cellSize * i)){
                                    tmp[0] = i + 1;
                                }
                            }
                            bP.drawArea[tmp[1]][tmp[0]].r = toolCollection.clickColour.r;
                            bP.drawArea[tmp[1]][tmp[0]].g = toolCollection.clickColour.g;
                            bP.drawArea[tmp[1]][tmp[0]].b = toolCollection.clickColour.b;
                            bP.drawArea[tmp[1]][tmp[0]].a = toolCollection.clickColour.a;
                        }                       
                    }
                else if(toolCollection.eraserTool){
                    if(inDrawArea(wP.cursorX, wP.cursorY, bP) && !inToolBar(wP.cursorX, wP.cursorY, bP, toolCollection)){
                        int tmp[2] = {0,0};
                        for(int i = 0; i < bP.board.x - 2; i++){
                            for(int j = 0; j < bP.board.y - 2; j++){
                                if((wP.cursorY - (bP.gridY+(3*bP.cellSize)) - 1) > (bP.cellSize * j)){
                                    tmp[1] = j + 1;
                                } 
                            }
                            if((wP.cursorX - (bP.gridX+(3*bP.cellSize)) - 1) > (bP.cellSize * i)){
                                tmp[0] = i + 1;
                            }
                        }
                        bP.drawArea[tmp[1]][tmp[0]].r = 0;
                        bP.drawArea[tmp[1]][tmp[0]].g = 0;
                        bP.drawArea[tmp[1]][tmp[0]].b = 0;
                        bP.drawArea[tmp[1]][tmp[0]].a = 0;
                    }  
                }
                }
                else{
                    if(!first){
                        first = true;
                    }
                }

            break; 

        case SDL_MOUSEBUTTONDOWN:
            if(event.button.button == SDL_BUTTON_LEFT){
                wP.leftClick = true;
                if(toolCollection.penTool){
                    if(inDrawArea(wP.cursorX, wP.cursorY, bP) && !inToolBar(wP.cursorX, wP.cursorY, bP, toolCollection)){
                        int tmp[2] = {0,0};
                        for(int i = 0; i < bP.board.x - 2; i++){
                            for(int j = 0; j < bP.board.y - 2; j++){
                                if((wP.cursorY - (bP.gridY+(3*bP.cellSize)) - 1) > (bP.cellSize * j)){
                                    tmp[1] = j + 1;
                                } 
                            }
                            if((wP.cursorX - (bP.gridX+(3*bP.cellSize)) - 1) > (bP.cellSize * i)){
                                tmp[0] = i + 1;
                            }
                        }
                        bP.drawArea[tmp[1]][tmp[0]].r = toolCollection.clickColour.r;
                        bP.drawArea[tmp[1]][tmp[0]].g = toolCollection.clickColour.g;
                        bP.drawArea[tmp[1]][tmp[0]].b = toolCollection.clickColour.b;
                        bP.drawArea[tmp[1]][tmp[0]].a = toolCollection.clickColour.a;
                    }  
                    
                }
                else if(toolCollection.eraserTool){
                    if(inDrawArea(wP.cursorX, wP.cursorY, bP) && !inToolBar(wP.cursorX, wP.cursorY, bP, toolCollection)){
                        int tmp[2] = {0,0};
                        for(int i = 0; i < bP.board.x - 2; i++){
                            for(int j = 0; j < bP.board.y - 2; j++){
                                if((wP.cursorY - (bP.gridY+(3*bP.cellSize)) - 1) > (bP.cellSize * j)){
                                    tmp[1] = j + 1;
                                } 
                            }
                            if((wP.cursorX - (bP.gridX+(3*bP.cellSize)) - 1) > (bP.cellSize * i)){
                                tmp[0] = i + 1;
                            }
                        }
                        bP.drawArea[tmp[1]][tmp[0]].r = 0;
                        bP.drawArea[tmp[1]][tmp[0]].g = 0;
                        bP.drawArea[tmp[1]][tmp[0]].b = 0;
                        bP.drawArea[tmp[1]][tmp[0]].a = 0;
                    }  
                }
                else if(toolCollection.zoomIn && !inToolBar(wP.cursorX, wP.cursorY, bP, toolCollection)){
                    bP.cellSize += 15;
                }
                else if(toolCollection.zoomOut && !inToolBar(wP.cursorX, wP.cursorY, bP, toolCollection)){
                    if(bP.cellSize - 15 > 4){
                        bP.cellSize -= 15;
                    }
                    else{
                        if(bP.cellSize - 4 > 4){
                            bP.cellSize -= 4;
                        }
                    }
                }
            }
        break;

        case SDL_MOUSEBUTTONUP:
                wP.leftClick = false;
                first = true;
                bP.fDisplaceX = bP.displaceX;
                bP.fDisplaceY = bP.displaceY;
        break;
        }
    }   
        this->update();
        this->render();
}

void window::render(){
    SDL_SetRenderDrawColor(rend, 24, 24, 24, 255);
    SDL_RenderClear(rend);
}

void window::update(){
    SDL_RenderPresent(rend);
}
