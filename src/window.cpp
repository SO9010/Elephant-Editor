#include "window.h"

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
    SDL_CreateWindowAndRenderer(windowWidth, windowHeight, flags, &wind, &rend);

}

void window::handleWindowEvent(int &boardX, int &boardY, int &cellSize, int &dispalceX, int &displaceY){
    SDL_Event event;
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if(SDL_WaitEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                running = false;
            break;
            case SDL_KEYDOWN:
                if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_P]){
                    boardX += 1;
                    boardY += 1;
                }
                if(state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_M]){
                    if(boardX > 4){
                        boardX -= 1;
                    }
                    if(boardY > 4){
                        boardY -= 1;
                    }
                } 
                /*  KeyBoardMove
                if(state[SDL_SCANCODE_W]){
                    displaceY -= 5;
                }                
                if(state[SDL_SCANCODE_S]){
                    displaceY += 5;
                }    
                if(state[SDL_SCANCODE_A]){
                    dispalceX -= 5;
                }                
                if(state[SDL_SCANCODE_D]){
                    dispalceX += 5;
                }
                */
            break;

            case SDL_MOUSEWHEEL:
                if(event.wheel.y > 0){
                    cellSize += 3;
                }
                else if(event.wheel.y < 0){
                    if(cellSize > 4){
                        cellSize -= 3;
                    }
                }
            break;
    
            case SDL_MOUSEMOTION:  
                int x;
                int y;
                xF = yF = 0;
                if(SDL_GetMouseState(&x, &y) & SDL_BUTTON_MMASK){
                    if(first){
                        first = false;
                        oX = x;
                        oY = y;
                        std::cout << oX << " | " << oY << std::endl;
                    }   
                    else{
                        xF = x;
                        yF = y;
                        dispalceX = -(oX - xF);
                        displaceY = -(oY - yF);
                    }
                }
                else{
                    if(!first){
                        first = true;
                    }
                }
            break; 
        case SDL_MOUSEBUTTONUP:
                int cx, cy;

                        SDL_GetMouseState(&cx, &cy);
                std::cout << cx << "|||" << cy << std::endl;
            first = true;
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

windowProperty window::windowProperties(){
    windowProperty wP;
    SDL_GetWindowSize(wind, &wP.w, &wP.h);
    wP.running = running;
    wP.rend = rend;

    return wP;
}   
