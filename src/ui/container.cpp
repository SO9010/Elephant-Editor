// This is a container for UI elements such as toolbars, 
//it will dynamically change to the size of contents and can be resized by user
#include "container.h"

container::container(){

}

container::~container(){

}

void container::addToContainer(int uiElementW, int uiElementH){
    sizeOfUiElementsW += uiElementW + gapX;
    sizeOfUiElementsH += uiElementH + gapY;
    dockOuter.h = sizeOfUiElementsH;
    dockOuter.w = sizeOfUiElementsW;
}

void container::addToContainerW(int uiElementW){
    sizeOfUiElementsW += uiElementW + gapX;
}

void container::addToContainerH(int uiElementH){
    sizeOfUiElementsH += uiElementH + gapY;
}

void container::renderContainer(){
    SDL_SetRenderDrawBlendMode(window::rend, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window::rend, 36 ,36, 36, 225);
    SDL_RenderFillRect(window::rend, &dockOuter);
}