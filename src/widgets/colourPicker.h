#include "includes.h"

class colourPicker{
public:
    colourPicker();
    ~colourPicker();
    void renderColourPicker(tools &toolCollection);
    void moveColourSelectLine(windowProperty wP);
    void moveHueSelectLine(windowProperty wP);
    void changePrimaryColour(SDL_Color &originalColour, SDL_Color &changeToColour);
    int w = 230, h = 100;
    SDL_Color hue;
private:
    int pick = 150;
    int x = 8, y = 8;
};