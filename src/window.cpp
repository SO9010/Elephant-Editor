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
    wP.cW = (wP.w/2) + bP.displaceX;
    wP.cH = (wP.h/2) + bP.displaceY;
}

void window::handleWindowEvent(boardPorperties &bP){
    if(SDL_WaitEvent(&event)){
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        updateWP(bP);
        switch(event.type){
            case SDL_QUIT:
                wP.running = false;
            break;
            case SDL_KEYDOWN:
                if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_P]){
                    bP.board.x += 1;
                    bP.board.y += 1;
                }
                if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_M]){
                    if(bP.board.x > 3){
                        bP.board.x -= 1;
                    }
                    if(bP.board.y > 3){
                        bP.board.y -= 1;
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
                else{
                    if(!first){
                        first = true;
                    }
                }

            break; 

        case SDL_MOUSEBUTTONDOWN:
            if(wP.cursorX > bP.gridX+(2*bP.cellSize) && wP.cursorX < bP.board.windowX && 
                    wP.cursorY > bP.gridY+(2*bP.cellSize) && wP.cursorY < bP.board.windowY){
                std::cout << "boobs" << std::endl;
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
