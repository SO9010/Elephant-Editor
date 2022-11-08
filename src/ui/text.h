#pragma once
#include "includes.h"

class text{
public:
    text();
    text(const char *text);
    ~text();
    void changeText(const char *text);
    void renderText();
    int x = 0, y = 0;
    int w = 90, h = 60;
    SDL_Color textColour = {255, 255, 255};
private:
    // change the path
    TTF_Font * font = TTF_OpenFont("/home/samio/Elephant-Editor/src/ui/fonts/openSans/OpenSans-VariableFont_wdth,wght.ttf", 30);;
    SDL_Surface * surface;
    SDL_Texture * texture;
    const char *message = "You need text here";
};