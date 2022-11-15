#include "colourPicker.h"

void drawSurfaceTexture(SDL_Surface * surface, int x, int y){
	SDL_Texture * text = SDL_CreateTextureFromSurface(window::rend, surface);
	SDL_Rect renderRect = {x, y, surface->w, surface->h};
	SDL_RenderCopy(window::rend, text, NULL, &renderRect);
	SDL_DestroyTexture(text);
}

void setPixel(SDL_Surface * surface, SDL_Color color, int x, int y)
{
	((char*)surface->pixels)[(x + y * surface->w) * 4    ] = color.b;
	((char*)surface->pixels)[(x + y * surface->w) * 4 + 1] = color.g;
   //wierd thing here with the colours i thought +2 was blue not red
	((char*)surface->pixels)[(x + y * surface->w) * 4 + 2] = color.r;
	((char*)surface->pixels)[(x + y * surface->w) * 4 + 3] = color.a;
}

SDL_Color lerp(SDL_Color a, SDL_Color b, float gradPoint, int w){
   SDL_Color lerpedColour{
      a.r + (b.r - a.r) *gradPoint/w,
      a.g + (b.g - a.g) *gradPoint/w,
      a.b + (b.b - a.b) *gradPoint/w
   };
   return lerpedColour;
}

SDL_Surface *createGradientSurface(SDL_Color hue, int w, int h, int pickX, int pickY, SDL_Color &returnColour){
   SDL_Color pixel = {0, 0, 0};
   SDL_Color displayHue = {255, 255, 255};
   SDL_Surface * gradient = SDL_CreateRGBSurface(0,
      w, h, 32, 0, 0, 0, 0);
   for(int cY = 0; cY < gradient->h; cY++){
      for(int cX = 0; cX < gradient->w; cX++){
         SDL_Color displayColour = lerp(pixel, lerp(displayHue, hue, cY, h), cX, w);
         SDL_Color inverse = lerp(pixel, lerp(displayHue, hue, cY, h), cX, w);
         inverse = {255 - inverse.r, 255 - inverse.g, 255 - inverse.b};
         setPixel(gradient, displayColour, cX, cY);
         if(cX == pickX){
            setPixel(gradient, inverse, cX, cY);
         }
         if(cY == pickY){
            setPixel(gradient, inverse, cX, cY);
         }
         if(cX == pickX && cY == pickY){
            returnColour = displayColour;
         }
      }
   }
   return gradient;
}

SDL_Surface *createHueSurface(SDL_Color &hue, int w, int h, int huePick){
   SDL_Color pixel = {255, 0, 0};
   SDL_Color nextColour = {255, 255, 0};
   SDL_Surface * hueSurface = SDL_CreateRGBSurface(0,
      w, h, 32, 0, 0, 0, 0);
   for(int cY = 0; cY < hueSurface->h; cY++){
      for(int cX = 0; cX < hueSurface->w; cX++){
         SDL_Color displayColour = lerp(pixel, nextColour, cY, h/6);
         SDL_Color inverse = lerp(pixel, lerp(pixel, nextColour, cY, h), cX, w);
         inverse = {255 - inverse.r, 255 - inverse.g, 255 - inverse.b};
         setPixel(hueSurface, displayColour, cX, cY);
         if(cY == huePick){
            hue = displayColour;
            setPixel(hueSurface, inverse, cX, cY);
         }
      }
      if(cY == h/6){
         pixel = nextColour;
         nextColour = {0,255,0};
      }
      else if(cY == (h/6)*2){
         pixel = nextColour;
         nextColour = {0,255,255};
      }
      else if(cY == (h/6)*3){
         pixel = nextColour;
         nextColour = {0,0,255};
      }
      else if(cY == (h/6)*4){
         pixel = nextColour;
         nextColour = {255,0,255};
      }
      else if(cY == (h/6)*5 || cY == (h/6)*6){
         pixel = nextColour;
         nextColour = {255,0,0};
      }
   }
   return hueSurface;
}

colourPicker::colourPicker(){
   gradSurface = createGradientSurface(hue, w/1.15, h/1.15, pickX, pickY, returnColour);
   hueSurface = createHueSurface(hue, w - (w/1.15), h, huePick);
}

colourPicker::~colourPicker(){
   SDL_FreeSurface(gradSurface);
   SDL_FreeSurface(hueSurface);
}

struct partialAdds{
   float r = 0; 
   float g = 0; 
   float b = 0; 
};

void colourPicker::renderColourPicker(tools &toolCollection, windowProperty wP){
   drawSurfaceTexture(gradSurface, x, y);
   drawSurfaceTexture(hueSurface, x + w/1.1, y);
   this->changePrimaryColour(toolCollection.clickColour, returnColour);
   if(moveColourSelect(wP)){
      gradSurface = createGradientSurface(hue, w/1.15, h/1.15, pickX, pickY, returnColour);
   }
   if(moveHueSelectLine(wP)){
      gradSurface = createGradientSurface(hue, w/1.15, h/1.15, pickX, pickY, returnColour);
      hueSurface = createHueSurface(hue, w - (w/1.15), h, huePick);
   }
}

bool colourPicker::moveColourSelect(windowProperty wP){
   if(wP.cursorX > x && wP.leftClick && wP.cursorX < x + gradSurface->w &&
         wP.cursorY > y && wP.cursorY < y + h/1.15){
      pickX = wP.cursorX;
      pickY = wP.cursorY;
      return true;
   }
   return false;
}

bool colourPicker::moveHueSelectLine(windowProperty wP){
   if(wP.cursorX > x + w/1.1 && wP.leftClick && wP.cursorX < x + w/1.1 + hueSurface->w &&
         wP.cursorY > y && wP.cursorY < y + h){
      huePick = wP.cursorY;
      return true;
   }
   return false;
}

void colourPicker::changePrimaryColour(SDL_Color &originalColour, SDL_Color &changeToColour){
   if(originalColour.r != changeToColour.r){
      originalColour.r = changeToColour.r;
   }
   if(originalColour.g != changeToColour.g){
      originalColour.g = changeToColour.g;
   }
   if(originalColour.b != changeToColour.b){
      originalColour.b = changeToColour.b;
   }
}