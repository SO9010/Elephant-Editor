#include "colourPicker.h"
colourPicker::colourPicker(){
}

colourPicker::~colourPicker(){
}

/*
void colourPicker::renderColourPicker(tools &toolCollection){
   
   container container;
   container.addToContainer(w + 16, h + 16);
   container.addToContainerH(40);
   container.addToContainerH(40);
   container.renderContainer();
   
   int cX = x;
   int cY = y;
   string rgb;
   int r = 0;
   int g = 0;
   int b = 0;
   int Atempr = 0;
   float Fhuer = hue.r;
   float Fhueg = hue.g;
   float Fhueb = hue.b;
   int Atempg = 0;
   int Atempb = 0;
   int Btempr = 0;
   int Btempg = 0;
   int Btempb = 0;
   for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
         SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
         SDL_RenderDrawPoint(window::rend, cX, cY);
         // draw colour picker line
         if(j == pickX){
            SDL_SetRenderDrawColor(window::rend, 255 - pixel.r, 255 - pixel.g, 255 - pixel.b, 200);
            SDL_RenderDrawPoint(window::rend, cX, cY);
         }
         else if(i == pickY){
            SDL_SetRenderDrawColor(window::rend, 255 - pixel.r, 255 - pixel.g, 255 - pixel.b, 200);
            SDL_RenderDrawPoint(window::rend, cX, cY);
         }
         if(j == pickX && i == pickY){
            this->changePrimaryColour(toolCollection.clickColour, pixel);
         }

         if(pixel.b + hue.b/100<= hue.b){
            Atempb= pixel.b + hue.b/100;
         }
         else{
            Atempb= hue.b;
         }
         if(pixel.r + hue.r/100 <= hue.r){
            Atempr= pixel.r + hue.r/100;
         }
         else{
            Atempr = hue.r;
         }
         if(pixel.g + hue.g/100 <= hue.g){
            if(hue.g/100<1)
            {
               Atempg = hue.g;
            }
            else
            {
               Atempg = pixel.g + hue.g/100;
            }
         }
         else{
            Atempg = hue.g;
         }
         white = {Uint8(255-pixel.r - r), Uint8(255-pixel.g - g), Uint8(255-pixel.b - b)};
         
         if(pixel.r + white.r <= 255){
             Btempr = pixel.r + white.r;
         }
         else{
            Btempr = 255;
         }
         if(pixel.g + white.g <= 255){
            Btempg = pixel.g + white.g;
         }
         else{
            Btempg = 255;
         }
         if(pixel.b + white.b <= 255){
            Btempb = pixel.b + white.b;
         }
         else{
            Btempb = 255;
         } 
         
         pixel.r = (Atempr+Btempr);//(j+1) + Btempr/(i+1));
         pixel.g = (Atempg+Btempg);//(j+1) + Btempg/(i+1)) ;
         pixel.b = (Atempb+Btempb);//(j+1) + Btempb/(i+1));
         cX++;
      }
      if(r + 1 < 255 - hue.r){
         r+=1;
      }
      if(g + 1< 255 - hue.g){
         g+=1;
      }
      if(b + 1 < 255 - hue.b){
         b+=1;
      }
      pixel.r = 0;
      pixel.b = 0;
      pixel.g = 0;
      cX = x;
      cY++;            
   }
   pixel.r = 255;
   pixel.g = 0;
   pixel.b = 0;
   SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
   // draw hue selector
   int changeDensity = 5;
   for(int i = 0; i < w; i++){
      if(pixel.r >= 255 && pixel.g <= 255 && pixel.b == 0){
         pixel.g+=changeDensity;
      }
      if(pixel.r <= 255 && pixel.r >= 0 && pixel.g >= 255 && pixel.b == 0){
         pixel.r-=changeDensity;
      }
      if(pixel.r == 0 && pixel.g >= 255 && pixel.b <= 255){
         pixel.b+=changeDensity;
      } 
      if(pixel.r == 0 && pixel.g >= 0 && pixel.g <= 255 && pixel.b >= 255){
         pixel.g-=changeDensity;
      }
      if(pixel.r <= 255 && pixel.g == 0 && pixel.b >= 255){
         pixel.r+=changeDensity;
      }
      if(pixel.r >= 255 && pixel.g == 0 && pixel.b >= 0 && pixel.b <= 255){
         pixel.b-=changeDensity;
      }
      SDL_RenderDrawLine(window::rend, cX, (h + 15), cX, (h+ 45));
      SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
      cX++;
      if(i == huePicker){
         hue.r = pixel.r;
         hue.g = pixel.g;
         hue.b = pixel.b;
         SDL_SetRenderDrawColor(window::rend, 255 - pixel.r, 255 - pixel.g, 255 - pixel.b, 200);
      }
   }
   cX = x;
   // draw primary colour preview
   for(int i = 0; i < w; i++){
      SDL_SetRenderDrawColor(window::rend, toolCollection.clickColour.r, toolCollection.clickColour.g, toolCollection.clickColour.b, 255);
      SDL_RenderDrawLine(window::rend, cX, (h+55), cX, (h+85));
      cX++;
   }
}



void colourPicker::renderColourPicker(tools &toolCollection){
   container container;
   container.addToContainer(w + 16, h + 16);
   container.addToContainerH(40);
   container.addToContainerH(40);
   container.renderContainer();
   int cX = x;
   int cY = y;
   int cRamp = 150;
   SDL_Color destHue = hue;
   SDL_Color idestHue = hue;
   SDL_Color jdestHue = hue;
   hue = {255,255,255};
   for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
         SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
         SDL_RenderDrawPoint(window::rend, cX, cY);
         // draw colour picker line
         if(j == pickX){
            SDL_SetRenderDrawColor(window::rend, 255 - pixel.r, 255 - pixel.g, 255 - pixel.b, 200);
            SDL_RenderDrawPoint(window::rend, cX, cY);
         }
         else if(i == pickY){
            SDL_SetRenderDrawColor(window::rend, 255 - pixel.r, 255 - pixel.g, 255 - pixel.b, 200);
            SDL_RenderDrawPoint(window::rend, cX, cY);
         }
         if(j == pickX && i == pickY){
            this->changePrimaryColour(toolCollection.clickColour, pixel);
         }

         if(pixel.b + jdestHue.b/cRamp<= 255){
            pixel.b += jdestHue.b/cRamp;
         }
         else{
            pixel.b  = 255;
         }
         if(pixel.r + jdestHue.r/cRamp <= 255){
            pixel.r += jdestHue.r/cRamp;
         }
         else{
            pixel.r = 255;
         }
         if(pixel.g + jdestHue.g/cRamp <= 255){
            pixel.g += jdestHue.g/cRamp;
         }
         else{
            pixel.g = 255;
         }
         cX++;
      }
      pixel.r = 0;
      pixel.b = 0;
      pixel.g = 0;
      
         if((jdestHue.b/cRamp)*i<= 255){
            pixel.b = ((255/cRamp)*i);
         }
         else{
            pixel.b  = 255;
         }
         if((jdestHue.r/cRamp)*i<= 255){
            pixel.r =((255/cRamp)*i);
         }
         else{
            pixel.r = 255;
         }
         if((jdestHue.r/cRamp)*i <= 255){
            pixel.g = ((255/cRamp)*i);
         }
         else{
            pixel.g = 255;
         }
     jdestHue = destHue;

      cX = x;
      cY++;            
   }
   pixel.r = 255;
   pixel.g = 0;
   pixel.b = 0;
   SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
   // draw hue selector
   int changeDensity = 5;
   for(int i = 0; i < w; i++){
      if(pixel.r >= 255 && pixel.g <= 255 && pixel.b == 0){
         pixel.g+=changeDensity;
      }
      if(pixel.r <= 255 && pixel.r >= 0 && pixel.g >= 255 && pixel.b == 0){
         pixel.r-=changeDensity;
      }
      if(pixel.r == 0 && pixel.g >= 255 && pixel.b <= 255){
         pixel.b+=changeDensity;
      } 
      if(pixel.r == 0 && pixel.g >= 0 && pixel.g <= 255 && pixel.b >= 255){
         pixel.g-=changeDensity;
      }
      if(pixel.r <= 255 && pixel.g == 0 && pixel.b >= 255){
         pixel.r+=changeDensity;
      }
      if(pixel.r >= 255 && pixel.g == 0 && pixel.b >= 0 && pixel.b <= 255){
         pixel.b-=changeDensity;
      }
      SDL_RenderDrawLine(window::rend, cX, (h + 15), cX, (h+ 45));
      SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
      cX++;
      if(i == huePicker){
         hue.r = pixel.r;
         hue.g = pixel.g;
         hue.b = pixel.b;
         SDL_SetRenderDrawColor(window::rend, 255 - pixel.r, 255 - pixel.g, 255 - pixel.b, 200);
      }
   }
   cX = x;
   // draw primary colour preview
   for(int i = 0; i < w; i++){
      SDL_SetRenderDrawColor(window::rend, toolCollection.clickColour.r, toolCollection.clickColour.g, toolCollection.clickColour.b, 255);
      SDL_RenderDrawLine(window::rend, cX, (h+55), cX, (h+85));
      cX++;
   }
}

*/
struct partialAdds{
   float r = 0; 
   float g = 0; 
   float b = 0; 
};
void colourPicker::renderColourPicker(tools &toolCollection){
   /*
   container container;
   container.addToContainer(w + 16, h + 16);
   container.addToContainerH(40);
   container.addToContainerH(40);
   container.renderContainer();
   */
   int cX = x;
   int cY = y;
   SDL_Color displayHue = {255,255,255};
   partialAdds pAdd;
   partialAdds pAddWhite;
   for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
         // render
         SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
         SDL_RenderDrawPoint(window::rend, cX, cY);
         // draw colour picker line
         if(j == pickX){
            SDL_SetRenderDrawColor(window::rend, 255 - pixel.r, 255 - pixel.g, 255 - pixel.b, 200);
            SDL_RenderDrawPoint(window::rend, cX, cY);
         }
         else if(i == pickY){
            SDL_SetRenderDrawColor(window::rend, 255 - pixel.r, 255 - pixel.g, 255 - pixel.b, 200);
            SDL_RenderDrawPoint(window::rend, cX, cY);
         }
         if(j == pickX && i == pickY){
            this->changePrimaryColour(toolCollection.clickColour, pixel);
         }
         pAdd.r += float(displayHue.r)/float(w/2);
         pAdd.g += float(displayHue.g)/float(w/2);
         pAdd.b += float(displayHue.b)/float(w/2);
         
         if(pAdd.r >= 1){
            if(pixel.r < 255){
               pixel.r += 1;
               pAdd.r-=int(pAdd.r);
            }   
         }
         if(pAdd.g >= 1){
            if(pixel.g < 255){
               pixel.g += 1;
               pAdd.g-=int(pAdd.g);
            }
         }
         if(pAdd.b >= 1){
            if(pixel.b < 255){
               pixel.b += 1;
               pAdd.b-=int(pAdd.b);
            }
         }

         cX++;
      }

      pAddWhite.r = float(255-hue.r)/float(h/2);
      pAddWhite.g = float(255-hue.g)/float(h/2);
      pAddWhite.b = float(255-hue.b)/float(h/2);

      if(pAddWhite.r >= 1){
         if(displayHue.r > hue.r){
            displayHue.r-=1;  
            pAddWhite.r -= int(pAddWhite.r);
         }
      }
      if(pAddWhite.g >= 1){
         if(displayHue.g > hue.g){
            displayHue.g-=1;
            pAddWhite.g -= int(pAddWhite.g);
         }
      }
      if(pAddWhite.b >= 1){
         if(displayHue.b > hue.b){
            displayHue.b-=1;  
            pAddWhite.b -= int(pAddWhite.b);
         }
      }

      pixel = {0,0,0};
      cX = x;
      cY++;            
   }
   pixel.r = 255;
   pixel.g = 0;
   pixel.b = 0;
   SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
   // draw hue selector
   int changeDensity = 5;
   for(int i = 0; i < w; i++){
      if(pixel.r >= 255 && pixel.g <= 255 && pixel.b == 0){
         pixel.g+=changeDensity;
      }
      if(pixel.r <= 255 && pixel.r >= 0 && pixel.g >= 255 && pixel.b == 0){
         pixel.r-=changeDensity;
      }
      if(pixel.r == 0 && pixel.g >= 255 && pixel.b <= 255){
         pixel.b+=changeDensity;
      } 
      if(pixel.r == 0 && pixel.g >= 0 && pixel.g <= 255 && pixel.b >= 255){
         pixel.g-=changeDensity;
      }
      if(pixel.r <= 255 && pixel.g == 0 && pixel.b >= 255){
         pixel.r+=changeDensity;
      }
      if(pixel.r >= 255 && pixel.g == 0 && pixel.b >= 0 && pixel.b <= 255){
         pixel.b-=changeDensity;
      }
      SDL_RenderDrawLine(window::rend, cX, (h + 15), cX, (h+ 45));
      SDL_SetRenderDrawColor(window::rend, pixel.r, pixel.g, pixel.b, 255);
      cX++;
      if(i == huePicker){
         hue.r = pixel.r;
         hue.g = pixel.g;
         hue.b = pixel.b;
         SDL_SetRenderDrawColor(window::rend, 255 - pixel.r, 255 - pixel.g, 255 - pixel.b, 200);
      }
   }
   cX = x;
   // draw primary colour preview
   for(int i = 0; i < w; i++){
      SDL_SetRenderDrawColor(window::rend, toolCollection.clickColour.r, toolCollection.clickColour.g, toolCollection.clickColour.b, 255);
      SDL_RenderDrawLine(window::rend, cX, (h+55), cX, (h+85));
      cX++;
   }
/*
   std::string rgb;
   rgbText.x = 5;
   rgb.append(std::to_string(toolCollection.clickColour.r));
   rgb.append(" , ");
   rgb.append(std::to_string(toolCollection.clickColour.g));
   rgb.append(" , ");
   rgb.append(std::to_string(toolCollection.clickColour.b));
   rgbText.changeText(rgb.c_str());
   rgbText.renderText();
   
   std::string hueT;
   hueText.x = 5;
   hueText.y = 180;

   hueT.append(std::to_string(hue.r));
   hueT.append(" , ");
   hueT.append(std::to_string(hue.g));
   hueT.append(" , ");
   hueT.append(std::to_string(hue.b));
   hueText.changeText(hueT.c_str());
   hueText.renderText();
*/
}
void colourPicker::moveColourSelectLine(windowProperty wP){
   if(wP.cursorX > x && wP.leftClick && wP.cursorX < x + w &&
         wP.cursorY > y && wP.cursorY < y + h){
      pickX = wP.cursorX;
      pickY = wP.cursorY;
   }
}

void colourPicker::moveHueSelectLine(windowProperty wP){
   if(wP.cursorX > x && wP.leftClick && wP.cursorX < x + w &&
         wP.cursorY > y  + h + 15 && wP.cursorY < y + h  + 45){
      huePicker = wP.cursorX;
   }
}

void colourPicker::changePrimaryColour(SDL_Color &originalColour, SDL_Color &changeToColour){
   originalColour.r = changeToColour.r;
   originalColour.g = changeToColour.g;
   originalColour.b = changeToColour.b;
}