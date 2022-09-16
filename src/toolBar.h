#include "window.h"

class toolBar{
public:
    toolBar();
    ~toolBar();
    
    static SDL_Color    primaryColour;
    tools               tools;
    void                renderToolBar(windowProperty wP);
    void                squareTool();
    void                triangelTool();
    void                circleTool();
    void                moveTool();
    void                penTool();
    void                eraserTool();
private:
    int                 height = 277;
};