#include "text.h"
text::text(){
}
text::text(const char *text){
    message = text;
}
text::~text(){
    TTF_CloseFont(font);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
void text::changeText(const char *text){
    message = text;
}
void text::renderText(){
    textColour = {255, 255, 255};
    surface = TTF_RenderText_Blended(font, message, textColour);
    texture = SDL_CreateTextureFromSurface(window::rend, surface);
    SDL_Rect dstrect = {x, y, w, h};
    SDL_RenderCopy(window::rend, texture, NULL, &dstrect);

}