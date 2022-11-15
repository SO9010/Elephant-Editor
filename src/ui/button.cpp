#include "button.h"

button::button() : buttonX(0), buttonY(0), buttonWidth(0), buttonHeight(0), passiveColour{60, 60, 60, 225}, activeColour{100, 100, 100, 140}{

}
button::~button(){

}
void button::showButton(){
    buttonProperties.x = buttonX;
    buttonProperties.y = buttonY;
    buttonProperties.w = buttonWidth;
    buttonProperties.h = buttonHeight;
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
        SDL_SetRenderDrawColor(window::rend, passiveColour.r, passiveColour.g, passiveColour.b, passiveColour.a/4);
    }
    
    if(SDL_RenderFillRect(window::rend, &buttonProperties) < 0){
        std::cout << SDL_GetError() << "In drawing button image" << std::endl;
    }
    if(buttonImage.size() > 1){
        buttonImageTexture = IMG_LoadTexture(window::rend, buttonImage.c_str());
        if(buttonImageTexture == NULL){
            std::cout << SDL_GetError() << std::endl;
        }
        SDL_Rect tmpButtonImage = buttonProperties;
        tmpButtonImage.w += - 2;
        tmpButtonImage.h += - 2;
        tmpButtonImage.x += + 1;
        tmpButtonImage.y += + 1;
        if(SDL_RenderCopy(window::rend, buttonImageTexture, NULL, &tmpButtonImage) < 0){
            std::cout << SDL_GetError() << std::endl;
        }
    }
}
bool button::clicked(windowProperty wP){
    if(wP.cursorX > buttonX && wP.leftClick && wP.cursorX < buttonX + buttonWidth &&
            wP.cursorY > buttonY && wP.cursorY < buttonY + buttonHeight){
        return true;
    }
    return false;
}