#pragma once 

#include <string>

#include "../globals.h"

class button{
public:
    button();
    ~button();
    void showButton();
    std::string buttonImage;
    bool clicked(windowProperty wP);
    int buttonX, buttonY;
    int buttonWidth, buttonHeight;
    SDL_Color activeColour, passiveColour;
    bool active;
    int type;                               // 0 = normal, 1 = checkbox
private:
    SDL_Rect buttonProperties;
    SDL_Texture *buttonImageTexture = NULL;
};

class toggleButton : button{

};