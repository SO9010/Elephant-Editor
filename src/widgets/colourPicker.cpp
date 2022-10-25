#include "colourPicker.h"

colourPicker::colourPicker(){
}

colourPicker::~colourPicker(){

}


void colourPicker::renderColourPicker(){
    container container;
    container.addToContainer(w + 16, h + 16);
    container.renderContainer();
    int cX = x;
    int cY = y;
    int r = 256, g = 256, b = 256;
    int brightness = 200;
                g += brightness;
            b += brightness;
            r += brightness;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){

            SDL_SetRenderDrawColor(window::rend, r, g, b, 255);
            SDL_RenderDrawPoint(window::rend, cX, cY);
            g--;
            cX++;
        }
        g--;
        r++;
        b--;
        cX = x;
        cY++;            
        //r = brightness;
        //g = brightness;
        //b = b * brightness;
    }
}

void colourPicker::renderColourPickerDot(){

}

SDL_Color colourPicker::getPixelColour(){
    
}
