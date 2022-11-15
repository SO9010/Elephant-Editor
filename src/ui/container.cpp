// This is a container for UI elements such as toolbars, 
// it will dynamically change to the size of contents and can be resized by user
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
    dockOuter.w = sizeOfUiElementsW;
}

void container::addToContainerH(int uiElementH){
    sizeOfUiElementsH += uiElementH + gapY;
    dockOuter.h = sizeOfUiElementsH;
}

void container::renderContainer(){
    dockOuter.y = y;
    SDL_SetRenderDrawColor(window::rend, 36 ,36, 36, 225);
    SDL_RenderFillRect(window::rend, &dockOuter);

    dockInner = dockOuter;
    dockInner.h -= 10;
    dockInner.w -= 10;
    dockInner.y += 5;
    dockInner.x += 5;

    SDL_SetRenderDrawColor(window::rend, 48, 48, 48, 225);
    SDL_RenderFillRect(window::rend, &dockInner);

}