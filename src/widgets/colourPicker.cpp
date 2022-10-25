#include "colourPicker.h"

colourPicker::colourPicker(){
}

colourPicker::~colourPicker(){

}

void colourPicker::renderColourPicker(tools &toolCollection){
   container container;
   container.addToContainer(w + 16, h + 16);
   container.addToContainerH(40);
   container.addToContainerH(40);
   container.renderContainer();
   int cX = x;
   int cY = y;
   SDL_Color pixel = {0, 0, 0};
   SDL_Color hue = {244, 45, 234};
   for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
         if(j < w/1.75){
            if(pixel.b + hue.b/75 <= hue.b){
               pixel.b += hue.b/75;
            }
            else{
               hue.b = hue.b;
            }
            if(pixel.r + hue.r/75 <= hue.r){
               pixel.r += hue.r/75;
            }
            else{
               pixel.r = hue.r;
            }
            if(pixel.g + hue.g/75 <= hue.g){
               pixel.g += hue.g/75;
            }
            else{
               pixel.g = hue.g;
            }
         }
         else if(j > w/1.5){
            if(pixel.b + 4 < 255){
               pixel.b += 4;
            }
            else{
               pixel.b = 255;
            }
            if(pixel.r + 4 < 255){
               pixel.r += 4;
            }
            else{
               pixel.r = 255;
            }
            if(pixel.g + 4 < 255){
               pixel.g += 4;
            }
            else{
               pixel.g = 255;
            }
         }
         SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
         SDL_RenderDrawPoint(window::rend, cX, cY);
         // draw colour picker line
         if(j == pick){
            this->changePrimaryColour(toolCollection.clickColour, pixel);
            SDL_SetRenderDrawColor(window::rend, 255 - pixel.r, 255 - pixel.g, 255 - pixel.b, 200);
            SDL_RenderDrawPoint(window::rend, cX, cY);
         }
         cX++;
      }
      pixel.r = 0;
      pixel.g = 0;
      pixel.b = 0;
      cX = x;
      cY++;            
   }
   pixel.r = 255;
   pixel.g = 0;
   pixel.b = 0;
   bool r = false;
   bool g = false;
   bool b = false;
   // draw hue selector
   for(int i = 0; i < w; i++){


      SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
      SDL_RenderDrawLine(window::rend, cX, (h + 15), cX, (h+ 45));
      cX++;
   }
   cX = x;
   // draw primary colour colour
   for(int i = 0; i < w; i++){
      SDL_SetRenderDrawColor(window::rend, toolCollection.clickColour.r, toolCollection.clickColour.g, toolCollection.clickColour.b, 255);
      SDL_RenderDrawLine(window::rend, cX, (h+55), cX, (h+85));
      cX++;
   }
}

void colourPicker::moveColourSelectLine(windowProperty wP){
   if(wP.cursorX > x && wP.leftClick && wP.cursorX < x + w &&
         wP.cursorY > y && wP.cursorY < y + h){
      pick = wP.cursorX - 8;
   }
}

void colourPicker::changePrimaryColour(SDL_Color &originalColour, SDL_Color &changeToColour){
   originalColour.r = changeToColour.r;
   originalColour.g = changeToColour.g;
   originalColour.b = changeToColour.b;
}
