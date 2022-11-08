#include "includes.h"

class colourPicker{
public:
    colourPicker();
    ~colourPicker();
    void renderColourPicker(tools &toolCollection);
    void moveColourSelectLine(windowProperty wP);
    void moveHueSelectLine(windowProperty wP);
    void changePrimaryColour(SDL_Color &originalColour, SDL_Color &changeToColour);
    SDL_Color hue;
private:
    text rgbText;
    text hueText;
    int pickX = 0;
    int pickY = 0;
    int huePicker = 0;
    int w = 300, h = 255;
    int x = 0, y = 0; 
    SDL_Color pixel = {0, 0, 0};
};