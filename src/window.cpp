#include "window.h"
#include "board.h"
#include "toolBar.h"

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

void setToolsToFalse(tools tools){
    tools.zoomIn = false;
    tools.zoomOut = false;
    tools.moveTool = false;
    tools.squareTool = false;
    tools.triangelTool = false;
    tools.circleTool = false;
    tools.penTool = false;
    tools.eraserTool = false;
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

bool window::inToolBar(int x, int y, boardPorperties bP, tools tools){
    if(x < 50 && (y > wP.cH-(tools.toolBarHeight/2) && y < wP.cH+(tools.toolBarHeight/2))){
        return true;
    }
    else{
        return false;
    }
}
void window::handleWindowEvent(boardPorperties &bP, tools tools){
    if(SDL_WaitEvent(&event)){
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        updateWP(bP);
        switch(event.type){
            case SDL_QUIT:
                wP.running = false;
            break;
            case SDL_KEYDOWN:
                if(state[SDL_SCANCODE_EQUALS]){
                    if(bP.board.x <= 128){
                        bP.board.x += 2;
                    }
                    if(bP.board.y <= 128){
                        bP.board.y += 2;
                    }
                }
                else if(state[SDL_SCANCODE_MINUS]){
                    if(bP.board.x > 4){
                        bP.board.x -= 2;
                    }
                    if(bP.board.y > 4){
                        bP.board.y -= 2;
                    }
                }
                else if(state[SDL_SCANCODE_F]){
                    if(tools.zoomIn){
                        setToolsToFalse(tools);
                        tools.zoomOut = true;
                    }
                    else if(!tools.zoomIn){
                        setToolsToFalse(tools);
                        tools.zoomIn = true;
                    }
                }
                else if(state[SDL_SCANCODE_M]){
                    setToolsToFalse(tools);
                    tools.moveTool = true;
                }
                else if(state[SDL_SCANCODE_E]){
                    setToolsToFalse(tools);
                    tools.eraserTool = true;
                }
                else if(state[SDL_SCANCODE_P]){
                    setToolsToFalse(tools);
                    tools.penTool = true;
                }
                else if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_C]){
                    SDL_Color tmp = {255,255,255,0};
                    bP.drawArea.clear();
                    bP.drawArea.resize(bP.board.x-2, std::vector<SDL_Color>(bP.board.y-2, tmp));
                }
                if(tools.zoomIn || tools.zoomOut){
                    if(state[SDL_SCANCODE_LALT]){
                        if(tools.zoomIn){
                            setToolsToFalse(tools);
                            tools.zoomOut = true;
                        }
                        else if(!tools.zoomIn){
                            setToolsToFalse(tools);
                            tools.zoomIn = true;
                        }
                    }
                }
                if(tools.penTool){
                    if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_1]){
                        tools.clickColour.r = 255;
                        tools.clickColour.g = 255;
                        tools.clickColour.b = 255;
                        tools.clickColour.a = 255;
                    }
                    if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_2]){
                        tools.clickColour.r = 0;
                        tools.clickColour.g = 0;
                        tools.clickColour.b = 0;
                        tools.clickColour.a = 255;                    
                    }
                    if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_3]){
                        tools.clickColour.r = 255;
                        tools.clickColour.g = 0;
                        tools.clickColour.b = 0;
                        tools.clickColour.a = 255;
                    }
                    if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_4]){
                        tools.clickColour.r = 0;
                        tools.clickColour.g = 255;
                        tools.clickColour.b = 0;
                        tools.clickColour.a = 255;
                    }
                    if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_5]){
                        tools.clickColour.r = 255;
                        tools.clickColour.g = 0;
                        tools.clickColour.b = 0;
                        tools.clickColour.a = 255;
                    }
                    if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_6]){
                        tools.clickColour.r = 0;
                        tools.clickColour.g = 255;
                        tools.clickColour.b = 0;
                        tools.clickColour.a = 255;
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
                    if(tools.moveTool){
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
                    if(tools.penTool){
                        if(inDrawArea(wP.cursorX, wP.cursorY, bP) && !inToolBar(wP.cursorX, wP.cursorY, bP, tools)){
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
                            bP.drawArea[tmp[1]][tmp[0]].r = tools.clickColour.r;
                            bP.drawArea[tmp[1]][tmp[0]].g = tools.clickColour.g;
                            bP.drawArea[tmp[1]][tmp[0]].b = tools.clickColour.b;
                            bP.drawArea[tmp[1]][tmp[0]].a = tools.clickColour.a;
                        }                       
                    }
                else if(tools.eraserTool){
                    if(inDrawArea(wP.cursorX, wP.cursorY, bP) && !inToolBar(wP.cursorX, wP.cursorY, bP, tools)){
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
                if(tools.penTool){
                    if(inDrawArea(wP.cursorX, wP.cursorY, bP) && !inToolBar(wP.cursorX, wP.cursorY, bP, tools)){
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
                        bP.drawArea[tmp[1]][tmp[0]].r = tools.clickColour.r;
                        bP.drawArea[tmp[1]][tmp[0]].g = tools.clickColour.g;
                        bP.drawArea[tmp[1]][tmp[0]].b = tools.clickColour.b;
                        bP.drawArea[tmp[1]][tmp[0]].a = tools.clickColour.a;
                    }  
                    
                }
                else if(tools.eraserTool){
                    if(inDrawArea(wP.cursorX, wP.cursorY, bP) && !inToolBar(wP.cursorX, wP.cursorY, bP, tools)){
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
                else if(tools.zoomIn && !inToolBar(wP.cursorX, wP.cursorY, bP, tools)){
                    bP.cellSize += 20;
                }
                else if(tools.zoomOut && !inToolBar(wP.cursorX, wP.cursorY, bP, tools)){
                    bP.cellSize -= 20;
                }

                if(inToolBar(wP.cursorX, wP.cursorY, bP, tools)){
                    int total = 0;
                    for(int x = wP.cH-(tools.toolBarHeight/2); x < wP.cH+(tools.toolBarHeight/2); x += 40){
                        if(wP.cursorY > x){
                            total++;
                        }
                    }
                    if(total == 1){
                        setToolsToFalse(tools);
                        tools.moveTool = true;
                    }
                    else if(total == 2){
                        if(tools.zoomIn){
                            setToolsToFalse(tools);
                            tools.zoomOut = true;
                        }
                        else if(!tools.zoomIn){
                            setToolsToFalse(tools);
                            tools.zoomIn = true;
                        }
                    }
                    else if(total == 3){
                        
                    }                    
                    else if(total == 4){
                        
                    }
                    else if(total == 5){
                        
                    }
                    else if(total == 6){
                        setToolsToFalse(tools);
                        tools.penTool = true;
                    }
                    else if(total == 7){
                        setToolsToFalse(tools);
                        tools.eraserTool = true;
                    }
                    std::cout << total << std::endl;
                }
            }
        break;

        case SDL_MOUSEBUTTONUP:
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
