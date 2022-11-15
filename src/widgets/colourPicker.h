#include "includes.h"

class colourPicker{
public:
    colourPicker();
    ~colourPicker();
    void renderColourPicker(tools &toolCollection, windowProperty wP);
    void changePrimaryColour(SDL_Color &originalColour, SDL_Color &changeToColour);
    SDL_Color hue = {255, 0, 0, 0};
private:
    bool moveColourSelect(windowProperty wP);
    bool moveHueSelectLine(windowProperty wP);
    void drawHue(SDL_Surface *gradient);
    void drawPreview();
    text rgbText;
    text hueText;
    int huePick;
    float w = 200, h = 300;
    int x = 0, y = 0; 
    int pickX = w/2;
    int pickY = h/2;
    SDL_Surface *gradSurface;
    SDL_Surface *hueSurface;
    SDL_Color returnColour;
};