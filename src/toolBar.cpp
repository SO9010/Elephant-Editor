#include "toolBar.h"

void toolBar::renderToolBar(windowProperty wP){
    SDL_Rect dockInner = {4, wP.cH-(height/2)+4, 42, height-8};
    SDL_Rect dockOuter = {0, wP.cH-(height/2), 50, height};

    SDL_SetRenderDrawColor(window::rend, 36 ,36, 36, 225);
    SDL_RenderFillRect(window::rend, &dockOuter);

    SDL_SetRenderDrawColor(window::rend, 48, 48, 48, 225);
    SDL_RenderFillRect(window::rend, &dockInner);
}