#include "button.h"
#include "../window.h"

button::button(){
    buttonX = buttonY = 0;
    buttonWidth = buttonHeight = 0;
    passiveColour = {60, 60, 60, 225}, activeColour = {100, 100, 100, 225};
}
button::~button(){

}
void button::showButton(){
    if(SDL_SetRenderDrawColor(window::rend, passiveColour.r, passiveColour.g, passiveColour.b, passiveColour.a) < 0){
        std::cout << SDL_GetError() << "In drawing button image" << std::endl;
    } 
    if(SDL_RenderDrawRect(window::rend, &buttonProperties) < 0){
        std::cout << SDL_GetError() << "In drawing button image" << std::endl;
    }     
    
    if(active){
        SDL_SetRenderDrawColor(window::rend, activeColour.r, activeColour.g, activeColour.b, activeColour.a);
    }
    else{
        SDL_SetRenderDrawColor(window::rend, passiveColour.r, passiveColour.g, passiveColour.b, passiveColour.a);
    }
    if(SDL_RenderFillRect(window::rend, &buttonProperties) < 0){
        std::cout << SDL_GetError() << "In drawing button image" << std::endl;
    }
    if(buttonImage.size() > 1){
        buttonImageTexture = IMG_LoadTexture(window::rend, buttonImage.c_str());
        SDL_Rect tmpButtonImage = buttonProperties;
        tmpButtonImage.w += - 2;
        tmpButtonImage.h += - 2;
        tmpButtonImage.x += + 1;
        tmpButtonImage.y += + 1;
        if(SDL_RenderCopy(window::rend, buttonImageTexture, NULL, &tmpButtonImage) < 0){
            std::cout << SDL_GetError() << "In drawing button image" << std::endl;
        }
    }
}
bool button::clicked(windowProperty wP){
    if(wP.cursorX < buttonX + buttonWidth && wP.cursorX > buttonX &&
        wP.cursorY < buttonY + buttonHeight && wP.cursorY > buttonX){
            return true;
        }
    return false;
}