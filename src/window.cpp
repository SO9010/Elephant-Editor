#include "window.h"
#include "board.h"

SDL_Renderer* window::rend = nullptr;


window::window(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    running = true; 
}

window::~window(){
    IMG_Quit();
    SDL_Quit();
    if(running){
        running = false;
    }
}

void window::init(){
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto windowWidth = DM.w / 1.5;
    auto windowHeight = DM.h / 1.5;
    Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    wP.running = running;
    SDL_CreateWindowAndRenderer(windowWidth, windowHeight, flags, &wind, &rend);
}

void window::updateWP(){
    SDL_GetWindowSize(wind, &windowWidth, &windowHight);
    wP.h = windowHight;
    wP.w = windowWidth;
    wP.running = running;
}

void window::handleWindowEvent(boardPorperties &bP){
    if(SDL_WaitEvent(&event)){
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        updateWP();
        switch(event.type){
            case SDL_QUIT:
                running = false;
            break;
            case SDL_KEYDOWN:
                if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_P]){
                    bP.board.x += 1;
                    bP.board.y += 1;
                }
                if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_M]){
                    if(bP.board.x > 4){
                        bP.board.x -= 1;
                    }
                    if(bP.board.y > 4){
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
                        
                        tmpX = dX;
                        tmpY = dy;

                        bP.dispalceX = dX + bP.fDisplaceX;
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
        break;

        case SDL_MOUSEBUTTONUP:
                first = true;
                bP.fDisplaceX = bP.dispalceX;
                bP.fDisplaceY = bP.displaceY;
                std::cout << bP.fDisplaceX << " || " << bP.fDisplaceY << std::endl;
        break;
        }
    }
}

void window::render(){
    SDL_SetRenderDrawColor(rend, 24, 24, 24, 255);
    SDL_RenderClear(rend);
}

void window::update(){
    SDL_RenderPresent(rend);
}
