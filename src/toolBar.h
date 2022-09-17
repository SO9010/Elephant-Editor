#include "window.h"

class toolBar{
public:
    toolBar();
    ~toolBar();
    
    static SDL_Color    primaryColour;
    tools               tools;
    void                renderToolBar(windowProperty wP, boardPorperties bP);
    void                updateTools();
    int                 height = 292;

private:
    void                changeCursor(std::string cursor, int offSet);

    void                zoomIn();
    void                zoomOut();
    void                moveTool();
    void                squareTool();
    void                triangelTool();
    void                circleTool();
    void                penTool();
    void                eraserTool();
};