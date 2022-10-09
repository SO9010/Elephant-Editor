#include "colourPicker.h"

colourPicker::colourPicker() : w(255), h(255){
}

colourPicker::~colourPicker(){

}

void colourPicker::renderColourPicker(){
    container container;
    container.addToContainer(255,255);
    container.renderContainer();
}

void colourPicker::renderColourPickerDot(){

}

SDL_Color colourPicker::getPixelColour(){
    
}
