#include "../window.h"
#include "../ui/container.h"

class colourPicker{
public:
    colourPicker();
    ~colourPicker();
    void renderColourPicker();
    void renderColourPickerDot();
    SDL_Color getPixelColour();
    int w, h;
private:
};