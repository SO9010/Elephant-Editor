#include "window.h"
#include "board.h"

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
    SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
}

void window::updateWP(boardPorperties bP){
    SDL_GetWindowSize(wind, &wP.w, &wP.h);
    wP.cWo = (wP.w/2) + bP.displaceX;
    wP.cW = (wP.w/2);
    wP.cHo = (wP.h/2) + bP.displaceY;
    wP.cH = (wP.h/2);
}

void window::handleWindowEvent(boardPorperties &bP, tools &tools){
    if(SDL_WaitEvent(&event)){
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        updateWP(bP);
        switch(event.type){
            case SDL_QUIT:
                wP.running = false;
            break;
            case SDL_KEYDOWN:
                if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_P]){
                    bP.board.x += 2;
                    bP.board.y += 2;
                }
               if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_M]){
                    if(bP.board.x > 4){
                        bP.board.x -= 2;
                    }
                    if(bP.board.y > 4){
                        bP.board.y -= 2;
                    }
                }
                if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_R]){
                    //bP.drawArea.clear();
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
                    if(wP.cursorX > bP.gridX+(2*bP.cellSize) && wP.cursorX < bP.board.windowX && 
                        wP.cursorY > bP.gridY+(2*bP.cellSize) && wP.cursorY < bP.board.windowY){
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
                        bP.drawArea[tmp[1]][tmp[0]] = &tools.clickColour;
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
               /*  if(wP.cursorX > bP.gridX+(2*bP.cellSize) && wP.cursorX < bP.board.windowX && 
                        wP.cursorY > bP.gridY+(2*bP.cellSize) && wP.cursorY < bP.board.windowY){

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
                    std::cout << tmp[0] << " x "<< tmp[1] << std::endl;
                    bP.drawArea[tmp[1]][tmp[0]] = &tools.clickColour;
                } */ 
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
