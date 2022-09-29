// This is a container for UI elements such as toolbars, 
//it will dynamically change to the size of contents and can be resized by user
#include "../globals.h"
#include "../window.h"

class container{
public:
    container();
    ~container();
    //IDEA: 2 vector with struct of wdith and height and of each row add up total X to get the width
    //      If you want to add something thats on the same line make it so its aligned
    //      Can set minimum size
    //      Double click on the resze tab to hide/show, resize frome there, only x size!!
    int minimumWidth;                                       //Well, its the minimum width you can resize it to.
    bool hidden;
    int x = 0, y = 0;
    int gapX, gapY;                                         //This gives the gaps inbetween the elements
    void addToContainer(int uiElementW, int uiElementH);    //Add to container, this takes in the width and height of the items.
    void addToContainerH(int uiElementH);
    void addToContainerW(int uiElementW);
    SDL_Rect dockInner = {0,0,0,0}, dockOuter = {0,0,0,0};
    void renderContainer();
private:
    void renderResizeTag();
    int sizeOfUiElementsW = 0;
    int sizeOfUiElementsH = 0;
};